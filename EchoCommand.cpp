#include <unistd.h>
#include "EchoCommand.h"
#include "Command.h"
#include "iostream"
using namespace std;

EchoCommand::EchoCommand(vector<string> args):
Command(std::move(args)){

}

int EchoCommand::execute() {
    // logic for the code
    for (int x = 0; x< args_.size();x++) {
        cout << args_[x] + " ";

    }
    cout <<"\n";

}
