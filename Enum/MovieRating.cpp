#include "MovieRating.h"

const string getRatingString(int index)
{
    string rating = ENUM_TO_STR(NOT_RATED);

    if (index == (int)MovieRating::G)
    {
        rating = ENUM_TO_STR(G);
    }
    else if (index == (int)MovieRating::PG)
    {
        rating = ENUM_TO_STR(PG);
    }
    else if (index == (int)MovieRating::PG13)
    {
        rating = ENUM_TO_STR(PG13);
    }
    else if (index == (int)MovieRating::R)
    {
        rating = ENUM_TO_STR(R);
    }

    return rating;
}
