#ifndef MOVIENODE_H
#define MOVIENODE_H

#include "Movie.h"

using namespace std;

namespace model {

class MovieNode
{
    public:
        MovieNode(Movie * movieInfo, MovieNode * nextName, MovieNode * nextLength, MovieNode * nextRating);
        virtual ~MovieNode();

        Movie* getMovieInfo();
        MovieNode* getNextName();
        MovieNode* getNextLength();
        MovieNode* getNextRating();

    protected:

    private:
        Movie* movieInfo;
        MovieNode* nextName;
        MovieNode* nextLength;
        MovieNode* nextRating;
};

}

#endif // MOVIENODE_H
