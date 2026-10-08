# include "parser.h"
#include <sstream>
using namespace std;

ParsedType parser::parse(string line) {

    // object that stores the stuff
    ParsedType result;

    istringstream ss(line);
    string token;

   // the command wanted by user
    if(ss >> token) {
        result.name = token;
    }

    // the args

    while (ss >> token) {
        result.args = token.
    }






};

