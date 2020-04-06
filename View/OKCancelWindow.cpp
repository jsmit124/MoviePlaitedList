#include "OKCancelWindow.h"

namespace view
{

//
// Constructs a ok/cancel window creating and initializing all the widgets taht will be displayed
//
// @precondition width > 0 AND height > 0
// @postcondition none
//
// @param width The width of the window
// @param height The height of the window
// @param title The title to display for the window
//
OKCancelWindow::OKCancelWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->buttonInvoked = WindowResult::NONE;

    begin();

    this->okButton = new Fl_Button(0, 0, 70, 30, "OK");
    this->okButton->callback(cbOk, this);

    this->cancelButton = new Fl_Button(0, 0, 70, 30, "Cancel");
    this->cancelButton->callback(cbCancel, this);

    end();

}

//
// The handler when OK is invoked
//
// @precondition widget != 0 AND data != 0
// @postcondition getWindowResult() == OKCancelWindow::OK
//
void OKCancelWindow::cbOk(Fl_Widget* widget, void* data)
{
    OKCancelWindow* window = (OKCancelWindow*)data;
    window->setWindowResult(OKCancelWindow::OK);
    window->okHandler();
}

//
// The handler when Cancel is invoked
//
// @precondition widget != 0 AND data != 0
// @postcondition getWindowResult() == OKCancelWindow::CANCEL
//
void OKCancelWindow::cbCancel(Fl_Widget* widget, void* data)
{
    OKCancelWindow* window = (OKCancelWindow*)data;
    window->setWindowResult(OKCancelWindow::CANCEL);
    window->cancelHandler();
}

//
// Sets the (x,y) location of the OK button
//
// @precondition none
// @postcondition none
//
void OKCancelWindow::setOKLocation(int x, int y)
{
    this->okButton->position(x, y);
}

//
// Sets the (x,y) location of the Cancel button
//
// @precondition none
// @postcondition none
//
void OKCancelWindow::setCancelLocation(int x, int y)
{
    this->cancelButton->position(x, y);
}

//
// Sets the WindowResult which indicates how the window was closed via OK or Cancel button or X'd out.
//
// @precondition none
// @postcondition none
//
// @param result The window result
//
OKCancelWindow::WindowResult OKCancelWindow::setWindowResult(OKCancelWindow::WindowResult result)
{
    this->buttonInvoked = result;
}


//
// Gets the sort window result which indicates how the window was closed via OK or Cancel button or X'd out.
//
// @precondition none
// @postcondition none
//
// @return The window result of how the window was closed
//
OKCancelWindow::WindowResult OKCancelWindow::getWindowResult()
{
    return this->buttonInvoked;
}

//
// Destructor that cleans up all allocated resources for the window
//
OKCancelWindow::~OKCancelWindow()
{
    delete this->okButton;
    delete this->cancelButton;
}

}
