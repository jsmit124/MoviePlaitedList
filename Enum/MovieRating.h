#ifndef MOVIERATING_H
#define MOVIERATING_H

#include "Utils.h"

#include <string>
using namespace std;

enum MovieRating {G, PG, PG13, R, NOT_RATED};

const string GET_RATING_STRING(int);

#endif // MOVIERATING_H
