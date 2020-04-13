#include "DeleteMovieWindow.h"

namespace view
{

DeleteMovieWindow::DeleteMovieWindow() : OKCancelWindow(330, 90, "Movie to delete")
{
    begin();

    this->nameInput = new Fl_Input(105, 15, 200, 25, "Name:");
    this->setOKLocation(90, 50);
    this->setCancelLocation(170, 50);

    end();
}

void DeleteMovieWindow::okHandler()
{
    this->name = this->nameInput->value();
    this->hide();
}

void DeleteMovieWindow::cancelHandler()
{
    this->name = "";
    this->hide();
}

const string DeleteMovieWindow::getName() const
{
    return this->name;
}

DeleteMovieWindow::~DeleteMovieWindow()
{
    delete this->nameInput;
}

}
