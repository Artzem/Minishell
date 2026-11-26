#include "Command.h"
#include "ExternalCommand.h"
#include <iostream>
#include<unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

ExternalCommand::ExternalCommand(string commandName, vector<string> args)
    : Command(std::move(args)),
      commandName_(std::move(commandName)) {}

int ExternalCommand::execute() {
    // Convert vector<string> into a vector<char*>.
    vector<char*> argv;

    argv.push_back(commandName_.data());

    for (string& arg : args_) {
        argv.push_back(arg.data());
    }

    argv.push_back(nullptr);


    // create the child fork
    pid_t code = fork();
    // check for error
    if (code == -1) {
        perror("fork");
        return 1;
    }
    // kid logic
    else if (code == 0) {
        if (execvp(commandName_.c_str(), argv.data()) == -1) {
            perror("execvp");
            exit(127);
        }


    }

    //slow down Dad
    else {
        waitpid(code,nullptr,0);


    }
 return 0;
}


