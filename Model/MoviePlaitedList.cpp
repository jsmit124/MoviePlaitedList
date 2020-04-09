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

        bool comesBeforeNext = toUpperCase(movie.getName()).compare(toUpperCase(currNodePtr->getNextName()->getMovieInfo()->getName())) < 0;
        if (comesBeforeNext)
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
            return;
        }
    }

    newMovieNode->setNextName(currNodePtr->getNextName());
    currNodePtr->setNextName(newMovieNode);

    //TODO add by length
    //TODO add by rating

    this->listSize++;
}

bool MoviePlaitedList::deleteMovieNodeByName(const string& movieName)
{
    MovieNode* prevNodePtr = 0;
    MovieNode* currNodePtr = this->headNameNode;
    string currName = "";

    while (currNodePtr != 0)
    {
        currName = currNodePtr->getMovieInfo()->getName();

        if (currName == movieName)
        {
            MovieNode* oldNextName = currNodePtr->getNextName();
            MovieNode* oldNextLength = currNodePtr->getNextLength();
            MovieNode* oldNextRating = currNodePtr->getNextRating();

            currNodePtr->setNextName(0);
            currNodePtr->setNextLength(0);
            currNodePtr->setNextRating(0);
            delete currNodePtr;

            if (prevNodePtr == 0)
            {
                this->headNameNode = oldNextName;
            }
            else
            {
                prevNodePtr->setNextName(oldNextName);
                prevNodePtr->setNextLength(oldNextLength);
                prevNodePtr->setNextRating(oldNextRating);
            }

            return true;
        }

        prevNodePtr = currNodePtr;
        currNodePtr = currNodePtr->getNextName();
    }

    return false;
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
