#pragma once
#include "Command.h"
using namespace std;


class InternalCommand: Command {

public:
    // constructor (here we need name and args) so make own
    explicit InternalCommand(string name, vector<string> args);

    // actual execution
     int execute() override;

};
