#include "DeleteMovieWindow.h"

#include <iostream>
using namespace std;

namespace view {

//
// Constructs an delete movie window creating and initializing all the widgets that will be displayed
//
// @precondition none
// @postcondition none
//
DeleteMovieWindow::DeleteMovieWindow() : OKCancelWindow(330, 90, "Movie to delete")
{
    begin();

    this->nameInput = new Fl_Input(105, 15, 200, 25, "Name:");
    this->setOKLocation(90, 50);
    this->setCancelLocation(170, 50);

    end();
}

//
// The instance handler when OK is invoked
//
// @precondition none
// @postcondition getLastName() == name user entered
//
void DeleteMovieWindow::okHandler()
{
    this->name = this->nameInput->value();
    this->hide();
}

//
// The instance handler when Cancel is invoked
//
// @precondition none
// @postcondition getLastName() == ""
//
void DeleteMovieWindow::cancelHandler()
{
    this->name = "";
    this->hide();
}

//
// Gets the name entered
//
// @precondition none
// @postcondition none
//
// @return The name entered
//
const string DeleteMovieWindow::getName() const
{
    return this->name;
}

//
// Destructor that cleans up all allocated resources for the window
//
DeleteMovieWindow::~DeleteMovieWindow()
{
    delete this->nameInput;
}

}
