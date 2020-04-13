#ifndef ADDMOVIEWINDOW_H
#define ADDMOVIEWINDOW_H

#include "Utils.h"

#include "MovieRating.h"

#include "OKCancelWindow.h"
#include "Movie.h"
using namespace model;

#include <Fl/Fl_Input.H>
#include <Fl/fl_ask.H>
#include <sstream>
using namespace std;

namespace view
{

//
// Defines the window where the user can enter the movie information.
//
class AddMovieWindow : public OKCancelWindow
{
public:
    /*
    * Constructs an add movie window creating and initializing all the widgets that will be displayed
    *
    * @precondition none
    * @postcondition none
    */
    AddMovieWindow();
    /*
    * Destructor that cleans up all allocated resources for the window
    */
    virtual ~AddMovieWindow();

    /*
    * The instance handler when OK is invoked
    *
    * @precondition none
    * @postcondition getMovie() == movie object created from data user entered
    */
    void okHandler();
    /*
    * The instance handler when cancel is invoked
    *
    * @precondition none
    * @postcondition getMovie() == 0
    */
    void cancelHandler();

    /*
    * Gets the new movie object based on what user entered
    *
    * @precondition none
    * @postcondition none
    *
    * @return The movie object
    */
    Movie* getMovie() const;

private:
    Fl_Input* nameInput;
    Fl_Input* studioInput;
    Fl_Input* yearInput;
    Fl_Input* ratingInput;
    Fl_Input* lengthInput;

    Movie* pMovie;

    MovieRating determineAndSetRatingBasedOnUserInput();
    int determineAndSetYearBasedOnUserInput();
    int determineAndSetLengthBasedOnUserInput();
};

}

#endif // ADDMOVIEWINDOW_H
