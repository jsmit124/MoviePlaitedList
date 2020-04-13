#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include "MovieNode.h"
#include "Movie.h"
using namespace model;

#include <string>
using namespace std;

namespace formatter
{
/*
* Handles implementation for the OutputFormatter class
*/
class OutputFormatter
{
public:
    /*
    * Constructs a new OutputFormatter object
    */
    OutputFormatter();
    /*
    * Destructs the OutputFormatter object
    */
    virtual ~OutputFormatter();
    /*
    * Formats the output ascending by name
    *
    * @precondition none
    * @postcondition none
    *
    * @param startNode
    *       The starting node for the method to iterate from
    * @param longestNameLength
    *       The length of the longest name in the list
    * @param longestStudioLength
    *       The length of the longest studio name in the list
    *
    * @return output
    *       The formatted string representing the movie list
    */
    const string formatMoviesAscendingByName(MovieNode*, int, int);
    /*
    * Formats the output decending by name
    *
    * @precondition none
    * @postcondition none
    *
    * @param startNode
    *       The starting node for the method to iterate from
    * @param longestNameLength
    *       The length of the longest name in the list
    * @param longestStudioLength
    *       The length of the longest studio name in the list
    *
    * @return output
    *       The formatted string representing the movie list
    */
    const string formatMoviesDecendingByName(MovieNode*, int, int);
    /*
    * Formats the output ascending by length
    *
    * @precondition none
    * @postcondition none
    *
    * @param startNode
    *       The starting node for the method to iterate from
    * @param longestNameLength
    *       The length of the longest name in the list
    * @param longestStudioLength
    *       The length of the longest studio name in the list
    *
    * @return output
    *       The formatted string representing the movie list
    */
    const string formatMoviesAscendingByLength(MovieNode*, int, int);
    /*
    * Formats the output decending by length
    *
    * @precondition none
    * @postcondition none
    *
    * @param startNode
    *       The starting node for the method to iterate from
    * @param longestNameLength
    *       The length of the longest name in the list
    * @param longestStudioLength
    *       The length of the longest studio name in the list
    *
    * @return output
    *       The formatted string representing the movie list
    */
    const string formatMoviesDecendingByLength(MovieNode*, int, int);
    /*
    * Formats the output ascending by rating
    *
    * @precondition none
    * @postcondition none
    *
    * @param startNode
    *       The starting node for the method to iterate from
    * @param longestNameLength
    *       The length of the longest name in the list
    * @param longestStudioLength
    *       The length of the longest studio name in the list
    *
    * @return output
    *       The formatted string representing the movie list
    */
    const string formatMoviesAscendingByRating(MovieNode*, int, int);
    /*
    * Formats the output decending by rating
    *
    * @precondition none
    * @postcondition none
    *
    * @param startNode
    *       The starting node for the method to iterate from
    * @param longestNameLength
    *       The length of the longest name in the list
    * @param longestStudioLength
    *       The length of the longest studio name in the list
    *
    * @return output
    *       The formatted string representing the movie list
    */
    const string formatMoviesDecendingByRating(MovieNode*, int, int);

private:
    const string formatMovieLineOutput(MovieNode*, int, int);
};

}

#endif // OUTPUTFORMATTER_H
