#ifndef SAVEFILEFORMATTER_H
#define SAVEFILEFORMATTER_H

#include "Utils.h"

#include "Movie.h"
#include "MovieNode.h"
using namespace model;

#include <string>
using namespace std;

namespace formatter
{

class SaveFileFormatter
{
    public:
        SaveFileFormatter();
        virtual ~SaveFileFormatter();

        const string formatMoviesForSave(MovieNode* startNode);

    protected:

    private:
};

}

#endif // SAVEFILEFORMATTER_H
