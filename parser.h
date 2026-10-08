#include <vector>
// creating a new Type
struct ParsedType {

    string name;
    vector <string> args;
};

class parser {

    ParsedType parse (string line);
};

