#include <filesystem>
using namespace std;
#include <iostream>
#include "shell.h"
#include "Executor.h"
#include <sstream>



        // Create Parser object
        parser parseObj;
        // Create a CommandFactory object
        CommandFactory factoryObj;
        // Create Executor object
        Executor executorObj;

      int shell::run() {
            int statusCode = 0;
          string line;
          while (true) {
              cout << "Enter a command and arg \n";
              if (!getline(cin,line) || line == "exit") {
                  break; // if error we exit
              }
              // parse the input and return an ParsedType
              ParsedType result = parseObj.parse(line);

              // Pass in the "result" to the command factory and returns a ptr
             unique_ptr<Command> command = factoryObj.create(result);


              // execute the command
             statusCode = executorObj.run(*command);
          }

            return statusCode;

      }