#ifndef MOVIEPLAITEDLIST_H
#define MOVIEPLAITEDLIST_H

#include "Utils.h"

#include "MovieNode.h"
#include "Movie.h"
using namespace model;

#include <string>
#include <iostream>
using namespace std;

namespace model
{
/*
* Handles implementation of the MoviePlaitedList class
*/
class MoviePlaitedList
{
public:
    /*
    * Constructs a new MoviePlaitedList object
    */
    MoviePlaitedList();
    /*
    * Destructs the MoviePlaitedList object
    */
    virtual ~MoviePlaitedList();

    /*
    * Sets up a new MoviePlaitedList if one does not already exist
    *
    * @precondition none
    * @postcondition this->headNameNode EQUALS movie
    *               AND this->headLengthNode EQUALS movie
    *               AND this->headRatingNode EQUALS movie
    *
    * @param movie
    *       The movie to make the new movie list with
    */
    void makeNewList(Movie&);

    /*
    * Adds the movie to the movie list
    *
    * @precondition none
    * @postcondition movie is added to the movie list
    *
    * @param movie
    *       The movie to add to the list
    *
    * @return void
    */
    void addMovieNode(Movie&);
    /*
    * Deletes the movie from the movie list
    *
    * @precondition none
    * @postcondition movie is deleted to the movie list
    *
    * @param movieName
    *       The name of the movie to delete from the list
    *
    * @return true if the movie was successfully deleted from the list;
    *           false otherwise
    */
    bool deleteMovieNode(const string&);

    /*
    * Returns the head name node
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->headNameNode
    */
    MovieNode* getHeadNameNode();
    /*
    * Returns the head length node
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->headLengthNode
    */
    MovieNode* getHeadLengthNode();
    /*
    * Returns the head rating node
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->headRatingNode
    */
    MovieNode* getHeadRatingNode();

    /*
    * Returns the length of the longest name in the list
    *
    * @precondition none
    * @postcondition none
    *
    * @return the longest name in the list
    */
    int getLongestNameLength();
    /*
    * Returns the length of the longest studio in the list
    *
    * @precondition none
    * @postcondition none
    *
    * @return the longest studio in the list
    */
    int getLongestStudioLength();
    /*
    * Returns the size of the list
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->listSize
    */
    int getListSize();

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

    void addMovieNodeByName(MovieNode*);
    void addMovieNodeByLength(MovieNode*);
    void addMovieNodeByRating(MovieNode*);

    bool deleteMovieNodeByName(const string&);
    bool deleteMovieNodeByLength(const string&);
    bool deleteMovieNodeByRating(const string&);
};

}

#endif // MOVIEPLAITEDLIST_H
