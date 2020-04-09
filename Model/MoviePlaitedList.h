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

        void addToHead(Movie&);
        MovieNode* getHeadNameNode();
        MovieNode* getHeadLengthNode();
        MovieNode* getHeadRatingNode();
        int getListSize();

        void addMovieNodeByName(Movie& movie);
        bool deleteMovieNodeByName(const string& movieName);

    protected:

    private:
        MovieNode* headNameNode;
        MovieNode* headLengthNode;
        MovieNode* headRatingNode;

        int listSize;

        void setNameHead(MovieNode* movie);
        MovieNode* peek(MovieNode* node);
};

}

#endif // MOVIEPLAITEDLIST_H
