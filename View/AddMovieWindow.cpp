#include "AddMovieWindow.h"

namespace view
{

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

void AddMovieWindow::okHandler()
{
    string name = this->nameInput->value();
    string studio = this->studioInput->value();

    MovieRating rating = this->determineAndSetRatingBasedOnUserInput();

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

MovieRating AddMovieWindow::determineAndSetRatingBasedOnUserInput()
{
    string ratingEntered = this->ratingInput->value();
    ratingEntered = toUpperCase(ratingEntered);

    MovieRating rating = MovieRating::NOT_RATED;

    if (ratingEntered == ENUM_TO_STR(G))
    {
        rating = MovieRating::G;
    }
    else if (ratingEntered == ENUM_TO_STR(PG))
    {
        rating = MovieRating::PG;
    }
    else if (ratingEntered == ENUM_TO_STR(PG13))
    {
        rating = MovieRating::PG13;
    }
    else if (ratingEntered == ENUM_TO_STR(R))
    {
        rating = MovieRating::R;
    }

    return rating;
}

int AddMovieWindow::determineAndSetYearBasedOnUserInput()
{
    string yearStr = this->yearInput->value();
    int year = toInt(yearStr, "Error converting year to an integer.");

    if (year < 1888)
    {
        throw "Please enter a value 1888 or higher for year.";
    }

    return year;
}


int AddMovieWindow::determineAndSetLengthBasedOnUserInput()
{
    string lengthStr = this->lengthInput->value();
    int length = toInt(lengthStr, "Error converting length to an integer.");

    if (length < 0)
    {
        throw "Please enter a positive value for length.";
    }

    return length;
}

void AddMovieWindow::cancelHandler()
{
    if (this->pMovie)
    {
        delete pMovie;
    }

    this->pMovie = 0;
    this->hide();
}

Movie* AddMovieWindow::getMovie() const
{
    return this->pMovie;
}

AddMovieWindow::~AddMovieWindow()
{
    delete this->nameInput;
    delete this->studioInput;
    delete this->yearInput;
    delete this->ratingInput;
    delete this->lengthInput;
}

}
