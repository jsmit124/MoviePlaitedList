#include "AddMovieWindow.h"

#include "Utils.h"

#include <Fl/fl_ask.H>
#include <sstream>
using namespace std;

namespace view
{

//
// Constructs an add movie window creating and initializing all the widgets that will be displayed
//
// @precondition none
// @postcondition none
//
AddMovieWindow::AddMovieWindow() : OKCancelWindow(330, 215, "Movie to add")
{
    const int X_INPUT_LOCATION = 110;

    this->pMovie = 0;

    begin();

    this->nameInput = new Fl_Input(X_INPUT_LOCATION, 15, 200, 25, "Name:");
    this->studioInput = new Fl_Input(X_INPUT_LOCATION, 45, 200, 25, "Studio:");
    this->yearInput = new Fl_Input(X_INPUT_LOCATION, 75, 60, 25, "Year:");
    this->ratingInput = new Fl_Input(X_INPUT_LOCATION, 105, 60, 25, "Rating:");
    this->lengthInput = new Fl_Input(X_INPUT_LOCATION, 135, 60, 25, "Length:");

    this->setOKLocation(90, 170);
    this->setCancelLocation(170, 170);

    end();
}

//
// The instance handler when OK is invoked
//
// @precondition none
// @postcondition getMovie() == movie object created from data user entered
//
void AddMovieWindow::okHandler()
{
    string name = this->nameInput->value();
    string studio = this->studioInput->value();

    Movie::Rating rating = this->determineAndSetRatingBasedOnUserInput();

    try
    {
        int year = this->determineAndSetYearBasedOnUserInput();
        int length = this->determineAndSetLengthBasedOnUserInput();
        this->pMovie = new Movie(name, studio, year, rating, length);
        this->hide();
    }
    catch (const char* message)
    {
        fl_message("%s", message);
    }

}

Movie::Rating AddMovieWindow::determineAndSetRatingBasedOnUserInput()
{
    string ratingEntered = this->ratingInput->value();
    ratingEntered = toUpperCase(ratingEntered);

    Movie::Rating rating = Movie::Rating::NOT_RATED;

    if (ratingEntered == ENUM_TO_STR(G))
    {
        rating = Movie::Rating::G;
    }
    else if (ratingEntered == ENUM_TO_STR(PG))
    {
        rating = Movie::Rating::PG;
    }
    else if (ratingEntered == ENUM_TO_STR(PG13))
    {
        rating = Movie::Rating::PG13;
    }
    else if (ratingEntered == ENUM_TO_STR(R))
    {
        rating = Movie::Rating::R;
    }

    return rating;
}

int AddMovieWindow::determineAndSetYearBasedOnUserInput()
{
    string yearStr = this->yearInput->value();
    int year = toInt(yearStr, "Error converting year to an integer.");
    return year;
}


int AddMovieWindow::determineAndSetLengthBasedOnUserInput()
{
    string lengthStr = this->lengthInput->value();
    int length = toInt(lengthStr, "Error converting length to an integer.");
    return length;
}

//
// The instance handler when cancel is invoked
//
// @precondition none
// @postcondition getMovie() == 0
//
void AddMovieWindow::cancelHandler()
{
    if (this->pMovie)
    {
        delete pMovie;
    }

    this->pMovie = 0;
    this->hide();
}

//
// Gets the new movie object based on what user entered
//
// @precondition none
// @postcondition none
//
// @return The movie object
//
Movie* AddMovieWindow::getMovie() const
{
    return this->pMovie;
}

//
// Destructor that cleans up all allocated resources for the window
//
AddMovieWindow::~AddMovieWindow()
{
    delete this->nameInput;
    delete this->studioInput;
    delete this->yearInput;
    delete this->ratingInput;
    delete this->lengthInput;
}

}
