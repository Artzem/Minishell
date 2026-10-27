using namespace std;
#include <iostream>
#include <sstream>
#include "shell.h"
#include "parser.h"

        // Create Parser object
        parser parseObj;

      int shell::run() {
          string line;
          while (true) {
              cout << "Enter a command and arg \n";
              if (!getline(cin,line) || line == "exit") {
                  break; // if error we exit
              }
              // parse the input and return an ParsedType
              ParsedType result = parseObj.parse(line);

              // Pass in the "result" to the command factory

          }


            return 0;
      }