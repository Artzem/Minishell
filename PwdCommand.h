#pragma once
#include "Command.h"
using namespace std;

class PwdCommand: public BuiltinCommand {

public:

 explicit PwdCommand(vector<string> args);
 int execute() override;
 string name() const override { return "PWD"; }



};
