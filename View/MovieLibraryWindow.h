#ifndef MOVIELIBRARYWINDOW_H
#define MOVIELIBRARYWINDOW_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>

#include <vector>
#include <string>
using namespace std;

#include "Controller/Controller.h"
using namespace controller;

namespace view
{

//
// Defines the window where a user can load, save, add, and delete movies from a movie library
//
class MovieLibraryWindow : public Fl_Window
{
public:
    //
    // Defines the sorting methods that can be used to sort the methods.
    //
    enum SortOrder {NAME_ASCENDING, NAME_DESCENDING, RATING_ASCENDING, RATING_DESCENDING, LENGTH_ASCENDING, LENGTH_DESCENDING};

private:
    static const int SORTING_GROUPS = 3;
    static const int SORTING_TYPES_PER_GROUP = 2;
    static const int TOTAL_SORTING_METHODS = SORTING_GROUPS * SORTING_TYPES_PER_GROUP;

    vector<string> sortingGroup = {"Name", "Rating", "Length"};
    vector<string> sortingTypes = {"Ascending", "Descending"};
    string* radioSortingLabels[TOTAL_SORTING_METHODS];

    Fl_Output *sortingOutputLabel;
    Fl_Group *sortingRadioGroup;
    Fl_Round_Button *sortingRadioGroupButton[TOTAL_SORTING_METHODS];
    SortOrder sortOrderSelection;

    Fl_Output *librarySummaryOutputLabel;

    Fl_Text_Buffer *summaryOutputTextBuffer;
    Fl_Text_Display *summaryOutputTextDisplay;

    Fl_Button* loadButton;
    Fl_Button* saveButton;
    Fl_Button* addButton;
    Fl_Button* deleteButton;

    string selectedFilename;

    Controller controller;

    void createAndDisplaySortingRadioButtons();
    void setSortOrderBasedOnSelection();

    void draw();

public:
    MovieLibraryWindow(int width, int height, const char* title);
    virtual ~MovieLibraryWindow();

    static void cbSortingMethodChanged(Fl_Widget* widget, void* data);
    void sortingMethodChanged();

    static void cbLoad(Fl_Widget* widget, void* data);
    static void cbSave(Fl_Widget* widget, void* data);
    const string promptUserForFilename(int type, const string& title);
    const string getFilename() const;

    static void cbAddMovie(Fl_Widget* widget, void* data);
    static void cbDeleteMovie(Fl_Widget* widget, void* data);

    MovieLibraryWindow::SortOrder getSortOrder() const;

    void setSummaryText(const string& outputText);
};

}

#endif // MOVIELIBRARYWINDOW_H
