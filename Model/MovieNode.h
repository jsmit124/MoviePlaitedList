#ifndef MOVIENODE_H
#define MOVIENODE_H

#include "Movie.h"

using namespace std;

namespace model {

class MovieNode
{
    public:
        MovieNode();
        MovieNode(Movie movie);
        virtual ~MovieNode();

        Movie* getMovieInfo();
        MovieNode* getNextName();
        MovieNode* getNextLength();
        MovieNode* getNextRating();

        void setNextName(MovieNode* nextName);
        void setNextLength(MovieNode* nextLength);
        void setNextRating(MovieNode* nextRating);

    protected:

    private:
        Movie* movieInfo;
        MovieNode* nextName;
        MovieNode* nextLength;
        MovieNode* nextRating;
};

}

#endif // MOVIENODE_H
