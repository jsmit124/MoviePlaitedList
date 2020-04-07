#include "MoviePlaitedList.h"

#include "MovieNode.h"
#include "Movie.h"

using namespace std;

namespace model
{

MoviePlaitedList::MoviePlaitedList():headNameNode(0), headLengthNode(0), headRatingNode(0), listSize(0)
{}

void MoviePlaitedList::addToHead(const Movie& movie)
{
    MovieNode* newHead = new MovieNode(movie);

    if (this->headNameNode == 0 && this->headLengthNode == 0 && this->headRatingNode == 0)
    {
        this->headNameNode = newHead;
        this->headLengthNode = newHead;
        this->headRatingNode = newHead;
    }
    else
    {
        newHead->setNextName(this->headNameNode);
        this->headNameNode = newHead;

        newHead->setNextLength(this->headLengthNode);
        this->headLengthNode = newHead;

        newHead->setNextRating(this->headRatingNode);
        this->headRatingNode = newHead;
    }

    this->listSize++;
}

void MoviePlaitedList::addMovieNode(const Movie& movie)
{
    MovieNode* newMovieNode = new MovieNode(movie);

}

MovieNode* MoviePlaitedList::getHeadNameNode()
{
    return this->headNameNode;
}

MovieNode* MoviePlaitedList::getHeadLengthNode()
{
    return this->headLengthNode;
}

MovieNode* MoviePlaitedList::getHeadRatingNode()
{
    return this->headRatingNode;
}

int MoviePlaitedList::getListSize()
{
    return this->listSize;
}

MoviePlaitedList::~MoviePlaitedList()
{
    //dtor
}

}
