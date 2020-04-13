#ifndef SAVEFILEFORMATTER_H
#define SAVEFILEFORMATTER_H

#include "Utils.h"
#include "MovieRating.h"

#include "Movie.h"
#include "MovieNode.h"
using namespace model;

#include <string>
using namespace std;

namespace formatter
{
/*
* Handles inplementation of the SavefileFormatter class
*/
class SaveFileFormatter
{
public:
    /*
    * Constructs a new SaveFileFormatter object
    */
    SaveFileFormatter();
    /*
    * Destructs a new SaveFileFormatter object
    */
    virtual ~SaveFileFormatter();

    /*
    * Formats the output in CSV format
    *
    * @precondition none
    * @postcondition none
    *
    * @param startNode
    *       The node for the method to start iteration from
    *
    * @return output
    *       The formatted string representing the movie list in CSV format
    */
    const string formatMoviesForSave(MovieNode*);
};

}

#endif // SAVEFILEFORMATTER_H
