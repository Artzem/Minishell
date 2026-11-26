#pragma once
#include "Command.h"
using namespace std;

class Executor {
public:
    int run(Command& command,ParsedType& parse) const;
};