#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>

using namespace std;

class JsonParser
{
public:
    JsonParser();
    string JsonGetUser();
    bool JsonGetAdmin();
};

#endif // JSONPARSER_H
