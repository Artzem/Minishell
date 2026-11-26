#pragma once
#include <vector>
using namespace std;
// creating a new Type
struct ParsedType {

    string name;
    vector <string> args;

    // if need redirection
    bool isOutput = false; // "eg: echo Artem > file.txt (replace current text)"
    bool isOutputEnd = false; // >> (appends)
    bool isInput = false; // "<" prints from file
    bool isPipe = false; // "|"
    string filePath;

};


class parser {

public:
    ParsedType parse(string line);
};