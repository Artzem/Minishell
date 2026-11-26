#pragma once
#include "Command.h"
using namespace std;

class ExternalCommand : public Command {

public:
    ExternalCommand(string commandName,vector<string>args);

    int execute() override;
    string name() const override { return "External";}

private:
    string commandName_;

};