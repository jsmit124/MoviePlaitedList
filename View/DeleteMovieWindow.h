#ifndef DELETEMOVIEWINDOW_H
#define DELETEMOVIEWINDOW_H

#include "OKCancelWindow.h"

#include <Fl/Fl_Input.H>

#include <string>
using namespace std;

namespace view
{

//
// Defines the window where the user can enter the movie name to delete
//
class DeleteMovieWindow : public OKCancelWindow
{
public:
    /*
    * Constructs an delete movie window creating and initializing all the widgets that will be displayed
    *
    * @precondition none
    * @postcondition none
    */
    DeleteMovieWindow();
    /*
    * Destructor that cleans up all allocated resources for the window
    */
    virtual ~DeleteMovieWindow();

    /*
    * The instance handler when OK is invoked
    *
    * @precondition none
    * @postcondition getLastName() == name user entered
    */
    void okHandler();
    /*
    * The instance handler when Cancel is invoked
    *
    * @precondition none
    * @postcondition getLastName() == ""
    */
    void cancelHandler();

    /*
    * Gets the name entered
    *
    * @precondition none
    * @postcondition none
    *
    * @return The name entered
    */
    const string getName() const;

private:
    Fl_Input* nameInput;
    string name;

};

}

#endif // DELETEMOVIEWINDOW_H
