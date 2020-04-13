#include "MovieRating.h"

const string GET_RATING_FROM_INT(int index)
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

MovieRating GET_RATING_FROM_STRING(const string& ratingEntered)
{
    MovieRating rating = MovieRating::NOT_RATED;

    if (ratingEntered == ENUM_TO_STR(G))
    {
        rating = MovieRating::G;
    }
    else if (ratingEntered == ENUM_TO_STR(PG))
    {
        rating = MovieRating::PG;
    }
    else if (ratingEntered == ENUM_TO_STR(PG13))
    {
        rating = MovieRating::PG13;
    }
    else if (ratingEntered == ENUM_TO_STR(R))
    {
        rating = MovieRating::R;
    }

    return rating;

}
