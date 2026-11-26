#pragma once

#include "Command.h"
using namespace std;


// inherit the Parent class
class EchoCommand: public Command{

    // Constructor
    public:
    EchoCommand(vector<string>args);

    int execute() override;
    string name() const override { return "Echo";}
};
