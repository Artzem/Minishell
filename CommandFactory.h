# pragma once
#include <memory>
#include "parser.h"
#include "Command.h"
using namespace std;

class CommandFactory{

public:
    unique_ptr <Command> create(ParsedType& parse) const;

};
