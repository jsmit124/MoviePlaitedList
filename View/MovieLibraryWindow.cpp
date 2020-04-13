#include "MovieLibraryWindow.h"

namespace view
{

MovieLibraryWindow::MovieLibraryWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->sortingOutputLabel = new Fl_Output(100, 25, 0, 0, "Sort order:");
    createAndDisplaySortingRadioButtons();

    this->librarySummaryOutputLabel = new Fl_Output(190, 110, 0, 0, "Movie library summary:");

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(20, 120, 500, 200);
    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);

    this->loadButton = new Fl_Button(120, 330, 70, 30, "Load");
    this->loadButton->callback(cbLoad, this);

    this->saveButton = new Fl_Button(200, 330, 70, 30, "Save");
    this->saveButton->callback(cbSave, this);

    this->addButton = new Fl_Button(280, 330, 70, 30, "Add");
    this->addButton->callback(cbAddMovie, this);

    this->deleteButton = new Fl_Button(360, 330, 70, 30, "Delete");
    this->deleteButton->callback(cbDeleteMovie, this);

    this->setSummaryText("Welcome to Movie Library by Justin Smith!");

    this->controller = Controller();

    end();
}

void MovieLibraryWindow::draw()
{
    Fl_Window::draw();
    fl_frame("AAAA", 20, 35, 500, 55);
}


void MovieLibraryWindow::createAndDisplaySortingRadioButtons()
{
    const int X_RADIO_GROUP = 35;
    const int Y_RADIO_GROUP = 45;
    const int WIDTH_RADIO_GROUP = 400;
    const int HEIGHT_RADIO_GROUP = 100;

    this->sortingRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->sortingRadioGroup->begin();

    for (int i=0; i<SORTING_GROUPS; i++)
    {
        for (int j = 0; j<SORTING_TYPES_PER_GROUP; j++)
        {
            string label = this->sortingGroup[i] + " " + this->sortingTypes[j];
            int offset = (i*SORTING_TYPES_PER_GROUP) + j;
            this->radioSortingLabels[offset] = new string(label);
            this->sortingRadioGroupButton[offset] = new Fl_Round_Button(X_RADIO_GROUP + i*160, Y_RADIO_GROUP + j*25, 12, 12, radioSortingLabels[offset]->c_str());
            this->sortingRadioGroupButton[offset]->type(FL_RADIO_BUTTON);
            this->sortingRadioGroupButton[offset]->callback(cbSortingMethodChanged, this);
        }
    }

    this->sortingRadioGroup->end();

    this->sortingRadioGroupButton[0]->set();
    this->sortOrderSelection = NAME_ASCENDING;
}

void MovieLibraryWindow::cbSortingMethodChanged(Fl_Widget* widget, void* data)
{
    MovieLibraryWindow* window = (MovieLibraryWindow*)data;
    window->sortingMethodChanged();
}

void MovieLibraryWindow::sortingMethodChanged()
{
    this->setSortOrderBasedOnSelection();
    this->setSummaryText(this->controller.getFormattedOutput(this->sortOrderSelection));
}

void MovieLibraryWindow::cbLoad(Fl_Widget* widget, void* data)
{
    MovieLibraryWindow* window = (MovieLibraryWindow*)data;
    window->promptUserForFilename(Fl_File_Chooser::SINGLE, "Movie file to load");
    bool fileRead = window->controller.readFile(window->getFilename());

    if (!fileRead)
    {
        window->setSummaryText("File could not be loaded.\nEither file does not exist or there was nothing to load.\nPlease try again.");
    }
    else
    {
        window->setSummaryText(window->controller.getFormattedOutput(window->sortOrderSelection));
    }

}

const string MovieLibraryWindow::promptUserForFilename(int type, const string& title)
{
    Fl_File_Chooser chooser(".", "*", type, title.c_str());
    chooser.show();

    while(chooser.shown())
    {
        Fl::wait();
    }

    if (chooser.value() != 0)
    {
        this->selectedFilename = chooser.value();
    }
    else
    {
        this->selectedFilename = "";
    }

    return this->selectedFilename;
}

const string MovieLibraryWindow::getFilename() const
{
    return this->selectedFilename;
}

void MovieLibraryWindow::cbSave(Fl_Widget* widget, void* data)
{
    MovieLibraryWindow* window = (MovieLibraryWindow*)data;
    window->promptUserForFilename(Fl_File_Chooser::CREATE, "Movie file to save to");
    bool fileWritten = window->controller.writeFile(window->getFilename());

    if (!fileWritten)
    {
        window->setSummaryText("File could not be saved.\nEither file does not exist or there was nothing to save.\nPlease try again.");
    }
    else
    {
        window->setSummaryText("File saved.");
    }
}

void MovieLibraryWindow::cbAddMovie(Fl_Widget* widget, void* data)
{
    MovieLibraryWindow* window = (MovieLibraryWindow*)data;
    AddMovieWindow addMovie;
    addMovie.set_modal();
    addMovie.show();

    while (addMovie.shown())
    {
        Fl::wait();
    }

    if (addMovie.getMovie() != 0)
    {
        auto pMovie = addMovie.getMovie();
        window->controller.addToMovieList(*pMovie);
        window->setSummaryText(window->controller.getFormattedOutput(window->sortOrderSelection));
    }
}

void MovieLibraryWindow::cbDeleteMovie(Fl_Widget* widget, void* data)
{
    MovieLibraryWindow* window = (MovieLibraryWindow*)data;

    DeleteMovieWindow deleteMovie;
    deleteMovie.set_modal();
    deleteMovie.show();

    while (deleteMovie.shown())
    {
        Fl::wait();
    }

    bool movieRemoved = window->controller.deleteFromMovieList(deleteMovie.getName());
    if (movieRemoved)
    {
        window->setSummaryText(window->controller.getFormattedOutput(window->sortOrderSelection));
    }
    else
    {
        window->setSummaryText("Remove could not be completed.\nMovie was not found or operation was cancelled.\nPlease try again.");
    }
}

void MovieLibraryWindow::setSortOrderBasedOnSelection()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        if (this->sortingRadioGroupButton[i]->value())
        {
            this->sortOrderSelection = (SortOrder)i;
        }
    }
}

void MovieLibraryWindow::setSummaryText(const string& outputText)
{
    this->summaryOutputTextBuffer->text(outputText.c_str());
}

SortOrder MovieLibraryWindow::getSortOrder() const
{
    return this->sortOrderSelection;
}

MovieLibraryWindow::~MovieLibraryWindow()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        delete this->radioSortingLabels[i];
        delete this->sortingRadioGroupButton[i];
    }

    delete this->sortingOutputLabel;

    delete this->librarySummaryOutputLabel;
    this->summaryOutputTextDisplay->buffer(0);
    delete this->summaryOutputTextBuffer;
    delete this->summaryOutputTextDisplay;

    delete this->loadButton;
    delete this->saveButton;
    delete this->addButton;
    delete this->deleteButton;
}

}
