# include "parser.h"
#include <sstream>
using namespace std;

ParsedType parser::parse(string line) {
    // object that stores the stuff
    ParsedType result;

    // the whole message is currently in "ss"
    istringstream ss(line);
    string token;

    // the command wanted by user
    if(ss >> token) {
        result.name = token;
    }

    // the args
    // 1 by 1 if ss--> token (then push to array)
    while (ss >> token) {

        if (token == ">") {
            result.isOutput = true;

            // next token should be the file name
            if (ss >> token) {
                result.filePath = token;
            }
        }
        else if (token == ">>") {
            result.isOutputEnd = true;
            // next token should be the file name
            if (ss >> token) {
                result.filePath = token;
            }
        }
       else  if (token == "<") {
            result.isInput = true;

          if (ss >> token){result.filePath = token;}
        }
      else  if (token == "|") {
            result.isPipe = true;
           

        }

        else {
            result.args.push_back(token);
        }
    }



    // return the result
    return result;
    
};

