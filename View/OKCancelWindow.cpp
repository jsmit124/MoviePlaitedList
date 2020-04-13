#include "OKCancelWindow.h"

namespace view
{

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

void OKCancelWindow::cbOk(Fl_Widget* widget, void* data)
{
    OKCancelWindow* window = (OKCancelWindow*)data;
    window->setWindowResult(OKCancelWindow::OK);
    window->okHandler();
}

void OKCancelWindow::cbCancel(Fl_Widget* widget, void* data)
{
    OKCancelWindow* window = (OKCancelWindow*)data;
    window->setWindowResult(OKCancelWindow::CANCEL);
    window->cancelHandler();
}

void OKCancelWindow::setOKLocation(int x, int y)
{
    this->okButton->position(x, y);
}

void OKCancelWindow::setCancelLocation(int x, int y)
{
    this->cancelButton->position(x, y);
}

OKCancelWindow::WindowResult OKCancelWindow::setWindowResult(OKCancelWindow::WindowResult result)
{
    this->buttonInvoked = result;
}

OKCancelWindow::WindowResult OKCancelWindow::getWindowResult()
{
    return this->buttonInvoked;
}

OKCancelWindow::~OKCancelWindow()
{
    delete this->okButton;
    delete this->cancelButton;
}

}
