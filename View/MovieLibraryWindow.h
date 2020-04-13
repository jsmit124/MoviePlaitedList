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
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <Fl/Fl_File_Chooser.H>

#include "SortOrder.h"

#include "DeleteMovieWindow.h"
#include "AddMovieWindow.h"
using namespace view;

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
    /*
    * Constructs a movie library window creating and initializing all the widgets that will be displayed
    *
    * @precondition width > 0 AND height > 0
    * @postcondition none
    *
    * @param width
    *       The width of the window
    * @param height
    *       The height of the window
    * @param title
    *       The title to display for the window
    */
    MovieLibraryWindow(int, int, const char*);
    /*
    * Destructor that cleans up all allocated resources for the window
    */
    virtual ~MovieLibraryWindow();

    /*
    * Callback when a radio button for the way to sort the movies has changed
    *
    * @precondition widget != 0 AND data != 0
    * @postcondition MovieLibraryWindow::getSortOrder() == value of new sort order selected
    *
    * @param widget
    *       The widget that initiatied the callback
    * @param data
    *       Any data that was passed with the call back. In this instance, a pointer to the window.
    */
    static void cbSortingMethodChanged(Fl_Widget*, void*);
    /*
    * Callback that is an instance function of the window class to encapsulate function
    *
    * @precondition none
    * @postcondition getSortOrder() == value of new sort order selected
    */
    void sortingMethodChanged();

    /*
    * Callback when the Load button is invoked
    *
    * @precondition widget != 0 AND data != 0
    * @postcondition MovieLibraryWindow::getFilename() == file selected by the user
    *
    * @param widget
    *       The widget that initiated the callback
    * @param data
    *       Any data that was passed with the call back. In this instance, a pointer to the window.
    */
    static void cbLoad(Fl_Widget*, void*);
    /*
    * Callback when the Save button is invoked
    *
    * @precondition widget != 0 AND data != 0
    * @postcondition MovieLibraryWindow::getFilename() == file selected by the user
    *
    * @param widget
    *       The widget that initiatied the callback
    * @param data
    *       Any data that was passed with the call back. In this instance, a pointer to the window.
    */
    static void cbSave(Fl_Widget*, void*);
    /*
    * Callback when the Load button is invoked
    *
    * @precondition type == Fl_File_Chooser type of SINGLE, MULTI, CREATE, or DIRECTORY
    * @postcondition MovieLibraryWindow::getFilename() == file selected by the user
    *
    * @param type
    *       Fl_File_Chooser type of SINGLE, MULTI, CREATE, or DIRECTORY
    * @param title
    *       Title to display for the file chooser
    *
    * @return The filename the user selected
    */
    const string promptUserForFilename(int, const string&);
    /*
    * Gets the filename the user selected when the file chooser was invoked
    *
    * @precondition none
    * @postcondition none
    *
    * @return The filename the user had selected when the file chooser was invoked
    */
    const string getFilename() const;

    /*
    * Callback when the Add button is invoked
    *
    * @precondition widget != 0 AND data != 0
    * @postcondition none
    *
    * @param widget
    *       The widget that initiatied the callback
    * @param data
    *       Any data that was passed with the call back. In this instance, a pointer to the window.
    */
    static void cbAddMovie(Fl_Widget*, void*);
    /*
    * Callback when the Delete button is invoked
    *
    * @precondition widget != 0 AND data != 0
    * @postcondition none
    *
    * @param widget
    *       The widget that initiatied the callback
    * @param data
    *       Any data that was passed with the call back. In this instance, a pointer to the window.
    */
    static void cbDeleteMovie(Fl_Widget*, void*);

    /*
    * Gets the sort order the user has selected
    *
    * @precondition none
    * @postcondition none
    *
    * @return The sort order the user has selected
    */
    SortOrder getSortOrder() const;

    /*
    * Sets the summary test to display in the movie library summary output
    *
    * @precondition none
    * @postcondition none
    *
    * @param outputText
    *       The text to display
    */
    void setSummaryText(const string&);

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

    /*
    * Overriding drawing of FL_Window so can draw a boxes around the sorting type radio buttons
    * to make them appear in a group
    */
    void draw();
};

}

#endif // MOVIELIBRARYWINDOW_H
