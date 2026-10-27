#include <vector>
using namespace std;
// creating a new Type
struct ParsedType {

    string name;
    vector <string> args;
};


class parser {

public:
    ParsedType parse(string line);
};