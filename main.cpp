#include "MovieLibraryWindow.h"
using namespace view;

/*
* The initial entry point for the program
*/
int main(int argc, char ** argv)
{
    MovieLibraryWindow mainWindow(540, 375, "Justin Smith’s Movie Database");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
