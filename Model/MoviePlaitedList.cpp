#include "MoviePlaitedList.h"
#include "MovieNode.h"

using namespace std;

namespace model
{

MoviePlaitedList::MoviePlaitedList()
{
    this->listSize = 0;
}

MoviePlaitedList::MoviePlaitedList(MovieNode headNode)
{
    this->headNameNode = &headNode;
    this->headLengthNode = &headNode;
    this->headRatingNode = &headNode;

    this->listSize = 1;
}

MovieNode * MoviePlaitedList::getHeadNameNode()
{
    return this->headNameNode;
}

MovieNode * MoviePlaitedList::getHeadLengthNode()
{
    return this->headLengthNode;
}

MovieNode * MoviePlaitedList::getHeadRatingNode()
{
    return this->headRatingNode;
}

int MoviePlaitedList::getListSize()
{
    return this->listSize;
}

void MoviePlaitedList::addMovieNode(MovieNode movieNode)
{
    //TODO
}

MoviePlaitedList::~MoviePlaitedList()
{
    //dtor
}

}
