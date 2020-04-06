#include "MovieNode.h"
#include "Movie.h"

using namespace std;

namespace model {
//
// TODO: Document this
//
MovieNode::MovieNode(Movie * movieInfo, MovieNode * nextName, MovieNode * nextLength, MovieNode * nextRating)
{
    this->movieInfo = movieInfo;
    this->nextName = nextName;
    this->nextLength = nextLength;
    this->nextRating = nextRating;
}

Movie * MovieNode::getMovieInfo()
{
    return this->movieInfo;
}

MovieNode * MovieNode::getNextName()
{
    return this->nextName;
}

MovieNode * MovieNode::getNextLength()
{
    return this->nextLength;
}

MovieNode * MovieNode::getNextRating()
{
    return this->nextRating;
}

MovieNode::~MovieNode()
{
    //dtor
}

}
