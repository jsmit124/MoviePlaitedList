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

        void makeNewList(Movie&);
        MovieNode* getHeadNameNode();
        MovieNode* getHeadLengthNode();
        MovieNode* getHeadRatingNode();

        int getLongestNameLength();
        int getLongestStudioLength();
        int getListSize();

        void addMovieNode(Movie& movie);
        void addMovieNodeByName(MovieNode*);
        void addMovieNodeByLength(MovieNode*);
        void addMovieNodeByRating(MovieNode*);

        bool deleteMovieNode(const string&);
        bool deleteMovieNodeByName(const string&);
        bool deleteMovieNodeByLength(const string&);
        bool deleteMovieNodeByRating(const string&);

    protected:

    private:
        MovieNode* headNameNode;
        MovieNode* headLengthNode;
        MovieNode* headRatingNode;

        int listSize;
        int longestNameLength;
        int longestStudioLength;
        int longestRatingLength;

        void setNameHead(MovieNode*);
        void setLengthHead(MovieNode*);
        void setRatingHead(MovieNode*);
};

}

#endif // MOVIEPLAITEDLIST_H
