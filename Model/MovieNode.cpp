#include "MovieNode.h"
#include "Movie.h"

using namespace std;

namespace model {
//
// TODO: Document this
//
MovieNode::MovieNode(Movie movie):movieInfo(&movie), nextName(0), nextLength(0), nextRating(0)
{}

Movie* MovieNode::getMovieInfo()
{
    return this->movieInfo;
}

MovieNode* MovieNode::getNextName()
{
    return this->nextName;
}

MovieNode* MovieNode::getNextLength()
{
    return this->nextLength;
}

MovieNode* MovieNode::getNextRating()
{
    return this->nextRating;
}

void MovieNode::setNextName(MovieNode* nextName)
{
    this->nextName = nextName;
}

void MovieNode::setNextLength(MovieNode* nextLength)
{
    this->nextLength = nextLength;
}

void MovieNode::setNextRating(MovieNode* nextRating)
{
    this->nextRating = nextRating;
}

MovieNode::~MovieNode()
{
    //dtor
}

}
