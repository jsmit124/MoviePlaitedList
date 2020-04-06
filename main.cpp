#include "MovieLibraryWindow.h"
using namespace view;

int main(int argc, char ** argv)
{
    MovieLibraryWindow mainWindow(540, 375, "A3: MoviePlaiter by ...");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
