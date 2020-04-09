#include "MoviePlaitedList.h"

#include "MovieNode.h"
#include "Movie.h"

#include "Utils.h"

#include <string>
#include <iostream>
using namespace std;

namespace model
{

MoviePlaitedList::MoviePlaitedList():headNameNode(0), headLengthNode(0), headRatingNode(0), listSize(0)
{}

void MoviePlaitedList::addToHead(Movie& movie)
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
        newHead->setNextLength(this->headLengthNode);
        this->headLengthNode = newHead;

        newHead->setNextRating(this->headRatingNode);
        this->headRatingNode = newHead;
    }

    this->listSize++;
}

void MoviePlaitedList::setNameHead(MovieNode* movieNode)
{
    movieNode->setNextName(this->headNameNode);
    this->headNameNode = movieNode;
}

void MoviePlaitedList::addMovieNodeByName(Movie& movie)
{
    MovieNode* newMovieNode = new MovieNode(movie);
    //TODO add by name

    MovieNode* currNodePtr = this->headNameNode;
    string currName = currNodePtr->getMovieInfo()->getName();

    while (toUpperCase(movie.getName()).compare(toUpperCase(currName)) > 0)
    {
        if (currNodePtr->getNextName() == 0)
        {
            break;
        }
        else if (toUpperCase(movie.getName()).compare(toUpperCase(currNodePtr->getNextName()->getMovieInfo()->getName())) < 0)
        {
            break;
        }

        currNodePtr = currNodePtr->getNextName();
        currName = currNodePtr->getMovieInfo()->getName();

    }

    if (currNodePtr == this->headNameNode)
    {
        if (toUpperCase(movie.getName()).compare(toUpperCase(currName)) < 0)
        {
            this->setNameHead(newMovieNode);
        }
        else
        {
            newMovieNode->setNextName(currNodePtr->getNextName());
            currNodePtr->setNextName(newMovieNode);
        }
    }
    else
    {
        newMovieNode->setNextName(currNodePtr->getNextName());
        currNodePtr->setNextName(newMovieNode);
    }

    //TODO add by length
    //TODO add by rating

    this->listSize++;
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
