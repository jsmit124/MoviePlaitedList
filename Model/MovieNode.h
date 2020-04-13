#ifndef MOVIENODE_H
#define MOVIENODE_H

#include "Movie.h"
using namespace model;

namespace model
{
/*
* Handles implementation of the MovieNode class
*/
class MovieNode
{
public:
    /*
    * Constructs a new generic MovieNode object
    */
    MovieNode();
    /*
    * Constructs a new MovieNode object with desired movie
    *
    * @param movie
    *       The movie to be stored in the movie node
    */
    MovieNode(Movie);
    /*
    * Destructs the MovieNode object
    */
    virtual ~MovieNode();

    /*
    * Returns the movie info stored in the movie node
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->movieInfo
    */
    Movie* getMovieInfo();
    /*
    * Returns the next name node stored in the movie node
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->nextNameNode
    */
    MovieNode* getNextName();
    /*
    * Returns the next length node stored in the movie node
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->nextLengthNode
    */
    MovieNode* getNextLength();
    /*
    * Returns the next rating node stored in the movie node
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->nextRatingNode
    */
    MovieNode* getNextRating();

    /*
    * Sets the next name node
    *
    * @precondition none
    * @postcondition none
    *
    * @param nextName
    *       The node to be set as this->nextNameNode
    */
    void setNextName(MovieNode*);
    /*
    * Sets the next length node
    *
    * @precondition none
    * @postcondition none
    *
    * @param nextLength
    *       The node to be set as this->nextLengthNode
    */
    void setNextLength(MovieNode*);
    /*
    * Sets the next rating node
    *
    * @precondition none
    * @postcondition none
    *
    * @param nextRating
    *       The node to be set as this->nextRatingNode
    */
    void setNextRating(MovieNode*);

private:
    Movie* movieInfo;
    MovieNode* nextName;
    MovieNode* nextLength;
    MovieNode* nextRating;
};

}

#endif // MOVIENODE_H
