#ifndef OKCANCELWINDOW_H
#define OKCANCELWINDOW_H

#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

namespace view
{

//
// Abstract class that can be used for any window that needs Ok and Cancel buttons on it.
//
class OKCancelWindow : public Fl_Window
{
public:
    enum WindowResult {OK, CANCEL, NONE};

private:
    Fl_Button* okButton;
    Fl_Button* cancelButton;

    WindowResult buttonInvoked;

public:
    /*
    * Constructs a ok/cancel window creating and initializing all the widgets taht will be displayed
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
    OKCancelWindow(int, int, const char*);
    /*
    * Destructor that cleans up all allocated resources for the window
    */
    virtual ~OKCancelWindow();

    /*
    * Sets the (x,y) location of the OK button
    *
    * @precondition none
    * @postcondition none
    */
    void setOKLocation(int, int);
    /*
    * Sets the (x,y) location of the Cancel button
    *
    * @precondition none
    * @postcondition none
    */
    void setCancelLocation(int, int);

    /*
    * The handler when OK is invoked
    *
    * @precondition widget != 0 AND data != 0
    * @postcondition getWindowResult() == OKCancelWindow::OK
    */
    static void cbOk(Fl_Widget*, void*);
    virtual void okHandler() = 0;

    /*
    * The handler when Cancel is invoked
    *
    * @precondition widget != 0 AND data != 0
    * @postcondition getWindowResult() == OKCancelWindow::CANCEL
    */
    static void cbCancel(Fl_Widget*, void*);
    virtual void cancelHandler() = 0;

    /*
    * Sets the WindowResult which indicates how the window was closed via OK or Cancel button or X'd out.
    *
    * @precondition none
    * @postcondition none
    *
    * @param result
    *       The window result
    */
    OKCancelWindow::WindowResult setWindowResult(OKCancelWindow::WindowResult);
    /*
    * Gets the sort window result which indicates how the window was closed via OK or Cancel button or X'd out.
    *
    * @precondition none
    * @postcondition none
    *
    * @return The window result of how the window was closed
    */
    OKCancelWindow::WindowResult getWindowResult();
};

}

#endif // OKCANCELWINDOW_H
