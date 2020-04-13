#include "MoviePlaitedList.h"

namespace model
{

MoviePlaitedList::MoviePlaitedList():headNameNode(0), headLengthNode(0), headRatingNode(0), listSize(0), longestNameLength(0), longestStudioLength(0)
{}

void MoviePlaitedList::makeNewList(Movie& movie)
{
    MovieNode* newHead = new MovieNode(movie);

    if (this->headNameNode == 0 && this->headLengthNode == 0 && this->headRatingNode == 0)
    {
        this->headNameNode = newHead;
        this->headLengthNode = newHead;
        this->headRatingNode = newHead;

        this->listSize++;
        this->longestNameLength = movie.getName().size();
        this->longestStudioLength = movie.getStudio().size();
    }
}

void MoviePlaitedList::setNameHead(MovieNode* movieNode)
{
    movieNode->setNextName(this->headNameNode);
    this->headNameNode = movieNode;
}

void MoviePlaitedList::setLengthHead(MovieNode* movieNode)
{
    movieNode->setNextLength(this->headLengthNode);
    this->headLengthNode = movieNode;
}

void MoviePlaitedList::setRatingHead(MovieNode* movieNode)
{
    movieNode->setNextRating(this->headRatingNode);
    this->headRatingNode = movieNode;
}

void MoviePlaitedList::addMovieNode(Movie& movie)
{
    MovieNode* newMovieNode = new MovieNode(movie);

    this->addMovieNodeByName(newMovieNode);
    this->addMovieNodeByLength(newMovieNode);
    this->addMovieNodeByRating(newMovieNode);

    this->listSize++;
    if (movie.getName().size() > this->longestNameLength)
    {
        this->longestNameLength = movie.getName().size();
    }

    if (movie.getStudio().size() > this->longestStudioLength)
    {
        this->longestStudioLength = movie.getStudio().size();
    }
}

void MoviePlaitedList::addMovieNodeByName(MovieNode* newMovieNode)
{
    string movieNodeName = newMovieNode->getMovieInfo()->getName();
    MovieNode* currNodePtr = this->headNameNode;
    string currName = currNodePtr->getMovieInfo()->getName();

    while (toUpperCase(movieNodeName).compare(toUpperCase(currName)) > 0)
    {
        if (currNodePtr->getNextName() == 0)
        {
            break;
        }

        bool comesBeforeNext = toUpperCase(movieNodeName).compare(toUpperCase(currNodePtr->getNextName()->getMovieInfo()->getName())) < 0;
        if (comesBeforeNext)
        {
            break;
        }

        currNodePtr = currNodePtr->getNextName();
        currName = currNodePtr->getMovieInfo()->getName();
    }

    if (currNodePtr == this->headNameNode)
    {
        if (toUpperCase(movieNodeName).compare(toUpperCase(currName)) < 0)
        {
            this->setNameHead(newMovieNode);
            return;
        }
    }

    newMovieNode->setNextName(currNodePtr->getNextName());
    currNodePtr->setNextName(newMovieNode);
}

void MoviePlaitedList::addMovieNodeByLength(MovieNode* newMovieNode)
{
    int movieNodeLength = newMovieNode->getMovieInfo()->getLength();
    string movieNodeName = newMovieNode->getMovieInfo()->getName();

    MovieNode* currNodePtr = this->headLengthNode;
    int currLength = currNodePtr->getMovieInfo()->getLength();
    string currName = currNodePtr->getMovieInfo()->getName();

    while (movieNodeLength >= currLength)
    {
        if (currNodePtr->getNextLength() == 0)
        {
            break;
        }

        bool lengthIsLessThanNext = movieNodeLength < currNodePtr->getNextLength()->getMovieInfo()->getLength();
        bool lengthIsEqualToNext = movieNodeLength == currNodePtr->getNextLength()->getMovieInfo()->getLength();
        bool nameComesBeforeNext = toUpperCase(movieNodeName).compare(toUpperCase(currNodePtr->getNextLength()->getMovieInfo()->getName())) < 0;
        if (lengthIsLessThanNext || (lengthIsEqualToNext && nameComesBeforeNext))
        {
            break;
        }

        currNodePtr = currNodePtr->getNextLength();
        currLength = currNodePtr->getMovieInfo()->getLength();
    }

    if (currNodePtr == this->headLengthNode)
    {
        if (movieNodeLength < currLength || (movieNodeLength == currLength && toUpperCase(movieNodeName).compare(toUpperCase(currName)) < 0))  //comes before header
        {
            this->setLengthHead(newMovieNode);
            return;
        }
    }

    newMovieNode->setNextLength(currNodePtr->getNextLength());
    currNodePtr->setNextLength(newMovieNode);
}

void MoviePlaitedList::addMovieNodeByRating(MovieNode* newMovieNode)
{
    MovieRating movieNodeRating = newMovieNode->getMovieInfo()->getRating();
    string movieNodeName = newMovieNode->getMovieInfo()->getName();

    MovieNode* currNodePtr = this->headRatingNode;
    MovieRating currRating = currNodePtr->getMovieInfo()->getRating();
    string currName = currNodePtr->getMovieInfo()->getName();

    while (movieNodeRating >= currRating)
    {
        if (currNodePtr->getNextRating() == 0)
        {
            break;
        }

        bool ratingIsLessThanNext = movieNodeRating < currNodePtr->getNextRating()->getMovieInfo()->getRating();
        bool ratingIsEqualToNext = movieNodeRating == currNodePtr->getNextRating()->getMovieInfo()->getRating();
        bool nameComesBeforeNext = toUpperCase(movieNodeName).compare(toUpperCase(currNodePtr->getNextRating()->getMovieInfo()->getName())) < 0;
        if (ratingIsLessThanNext || (ratingIsEqualToNext && nameComesBeforeNext))
        {
            break;
        }

        currNodePtr = currNodePtr->getNextRating();
        currRating = currNodePtr->getMovieInfo()->getRating();
    }

    if (currNodePtr == this->headRatingNode)
    {
        if (movieNodeRating < currRating || movieNodeRating == currRating && toUpperCase(movieNodeName).compare(toUpperCase(currName)) < 0) //comes before header
        {
            this->setRatingHead(newMovieNode);
            return;
        }
    }

    newMovieNode->setNextRating(currNodePtr->getNextRating());
    currNodePtr->setNextRating(newMovieNode);
}

bool MoviePlaitedList::deleteMovieNode(const string& movieName)
{
    bool deletedLengthNode, deletedRatingNode;
    bool movieFound = this->deleteMovieNodeByName(movieName);

    if (movieFound)
    {
        deletedLengthNode = this->deleteMovieNodeByLength(movieName);
        deletedRatingNode = this->deleteMovieNodeByRating(movieName);
    }

    if (deletedLengthNode && deletedRatingNode)
    {
        return true;
    }

    return false;
}

bool MoviePlaitedList::deleteMovieNodeByName(const string& movieName)
{
    MovieNode* prevNodePtr = 0;
    MovieNode* currNodePtr = this->headNameNode;
    string currName;

    while (currNodePtr != 0)
    {
        currName = currNodePtr->getMovieInfo()->getName();

        if (toUpperCase(currName) == toUpperCase(movieName))
        {
            MovieNode* oldNextName = currNodePtr->getNextName();

            if (currNodePtr == this->headNameNode)
            {
                this->headNameNode = oldNextName;
            }
            else
            {
                prevNodePtr->setNextName(oldNextName);
            }

            currNodePtr->setNextName(0);
            return true;
        }

        prevNodePtr = currNodePtr;
        currNodePtr = currNodePtr->getNextName();
    }

    return false;
}

bool MoviePlaitedList::deleteMovieNodeByLength(const string& movieName)
{
    MovieNode* prevNodePtr = 0;
    MovieNode* currNodePtr = this->headLengthNode;
    string currName;

    while (currNodePtr != 0)
    {
        currName = currNodePtr->getMovieInfo()->getName();

        if (toUpperCase(currName) == toUpperCase(movieName))
        {
            MovieNode* oldNextLength = currNodePtr->getNextLength();

            if (currNodePtr == this->headLengthNode)
            {
                this->headLengthNode = oldNextLength;
            }
            else
            {
                prevNodePtr->setNextLength(oldNextLength);
            }

            currNodePtr->setNextLength(0);
            return true;
        }

        prevNodePtr = currNodePtr;
        currNodePtr = currNodePtr->getNextLength();
    }

    return false;
}

bool MoviePlaitedList::deleteMovieNodeByRating(const string& movieName)
{
    MovieNode* prevNodePtr = 0;
    MovieNode* currNodePtr = this->headRatingNode;
    string currName;

    while (currNodePtr != 0)
    {
        currName = currNodePtr->getMovieInfo()->getName();

        if (toUpperCase(currName) == toUpperCase(movieName))
        {
            MovieNode* oldNextRating = currNodePtr->getNextRating();

            if (currNodePtr == this->headRatingNode)
            {
                this->headRatingNode = oldNextRating;
            }
            else
            {
                prevNodePtr->setNextRating(oldNextRating);
            }
            ;
            currNodePtr->setNextRating(0);
            return true;
        }

        prevNodePtr = currNodePtr;
        currNodePtr = currNodePtr->getNextRating();
    }

    return false;
}

int MoviePlaitedList::getLongestNameLength()
{
    return this->longestNameLength;
}

int MoviePlaitedList::getLongestStudioLength()
{
    return this->longestStudioLength;
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
