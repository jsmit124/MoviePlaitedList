#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include "MovieNode.h"
#include "Movie.h"
using namespace model;

#include <string>
using namespace std;

namespace formatter {

class OutputFormatter
{
    public:
        OutputFormatter();
        virtual ~OutputFormatter();

        const string formatMoviesAscendingByName(MovieNode*, int, int);
        const string formatMoviesDecendingByName(MovieNode*, int, int);
        const string formatMoviesAscendingByLength(MovieNode*, int, int);
        const string formatMoviesDecendingByLength(MovieNode*, int, int);
        const string formatMoviesAscendingByRating(MovieNode*, int, int);
        const string formatMoviesDecendingByRating(MovieNode*, int, int);

    protected:

    private:
        const string formatMovieLineOutput(MovieNode*, int, int);
};

}

#endif // OUTPUTFORMATTER_H
