#ifndef MOVIEPLAITEDLIST_H
#define MOVIEPLAITEDLIST_H

#include "MovieNode.h"

namespace model
{

class MoviePlaitedList
{
    public:
        MoviePlaitedList();
        virtual ~MoviePlaitedList();

        void addToHead(const Movie&);
        MovieNode* getHeadNameNode();
        MovieNode* getHeadLengthNode();
        MovieNode* getHeadRatingNode();
        int getListSize();

        void addMovieNode(const Movie& movie);

    protected:

    private:
        MovieNode* headNameNode;
        MovieNode* headLengthNode;
        MovieNode* headRatingNode;

        int listSize;
};

}

#endif // MOVIEPLAITEDLIST_H
