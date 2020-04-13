#include "Utils.h"

const string toUpperCase(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::toupper);

    return text;
}

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
