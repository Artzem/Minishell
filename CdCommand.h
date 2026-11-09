#pragma once
#include <unistd.h>
#include "Command.h"
using namespace std;

// inherit from "Command"
class CdCommand : public BuiltinCommand {

public:
    explicit CdCommand(vector<string> args);

    int execute() override;
    string name() const override { return "CD"; }
    
};



