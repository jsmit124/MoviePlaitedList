#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

#define ENUM_TO_STR(ENUM) std::string(#ENUM)

const string toUpperCase(string text);
int toInt(const string& text, const char* errorMessage);

#endif // UTILS_H
