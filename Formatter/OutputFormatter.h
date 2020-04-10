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

        const string formatMoviesAscendingByName(MovieNode* startNode, int, int);
        const string formatMoviesDecendingByName(MovieNode* startNode, int, int);
        const string formatMoviesAscendingByLength(MovieNode* startNode, int, int);
        const string formatMoviesDecendingByLength(MovieNode* startNode, int, int);
        const string formatMoviesAscendingByRating(MovieNode* startNode, int, int);
        const string formatMoviesDecendingByRating(MovieNode* startNode, int, int);

    protected:

    private:
        const string formatMovieLineOutput(MovieNode* startNode, int, int);
};

}

#endif // OUTPUTFORMATTER_H
