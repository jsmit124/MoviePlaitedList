#include "Utils.h"

#include <algorithm>
#include <sstream>

//
// Converts and returns string in uppercase
//
// @precondition none
// @postcondition none
//
// @param text the text to convert to upper case
//
// @return Uppercase version of the string
//
const string toUpperCase(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::toupper);

    return text;
}

//
// Converts passed in string to an int
//
// @precondition none
// @postcondition none
// @throws Exception if text cannot be converted to an int
//
// @param text text to convert to an int
// @param errorMessage message thrown if a problem occurs when converting text to an int
//
// @return text converted to an int
//
int toInt(const string& text, const char* errorMessage)
{
    istringstream streamConversion(text);
    int value = 0;
    if (!(streamConversion >> value))
    {
        throw errorMessage;
    }

    return value;

}
