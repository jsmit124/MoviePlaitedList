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

        const string formatMoviesAscendingByName(MovieNode* startNode);
        const string formatMoviesDecendingByName(MovieNode* startNode);
        const string formatMoviesAscendingByLength(MovieNode* startNode);
        const string formatMoviesDecendingByLength(MovieNode* startNode);
        const string formatMoviesAscendingByRating(MovieNode* startNode);
        const string formatMoviesDecendingByRating(MovieNode* startNode);

    protected:

    private:
};

}

#endif // OUTPUTFORMATTER_H
