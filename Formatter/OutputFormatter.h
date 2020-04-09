#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include "MovieNode.h"
#include "Movie.h"
using namespace model;

#include <string>
using namespace std;

namespace formatter {

class OutputFormatter
{
    public:
        OutputFormatter();
        virtual ~OutputFormatter();

        const string formatMoviesAscendingByName(MovieNode* startNode);

    protected:

    private:
};

}

#endif // OUTPUTFORMATTER_H
