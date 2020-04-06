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
private:
    Fl_Input* nameInput;
    string name;

public:
    DeleteMovieWindow();
    virtual ~DeleteMovieWindow();

    void okHandler();
    void cancelHandler();

    const string getName() const;
};

}

#endif // DELETEMOVIEWINDOW_H
