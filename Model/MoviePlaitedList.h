#ifndef MOVIEPLAITEDLIST_H
#define MOVIEPLAITEDLIST_H
#include "MovieNode.h"

namespace model {

class MoviePlaitedList
{
    public:
        MoviePlaitedList();
        MoviePlaitedList(MovieNode headNode);
        virtual ~MoviePlaitedList();

        MovieNode * getHeadNameNode();
        MovieNode * getHeadLengthNode();
        MovieNode * getHeadRatingNode();
        int getListSize();

        void addMovieNode(MovieNode movieNode);

    protected:

    private:
        MovieNode * headNameNode;
        MovieNode * headLengthNode;
        MovieNode * headRatingNode;

        int listSize;
};

}

#endif // MOVIEPLAITEDLIST_H
