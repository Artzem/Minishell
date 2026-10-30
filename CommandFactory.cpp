#pragma once
#include "CommandFactory.h"
#include "CdCommand.h"
#include "Command.h"
using namespace std;


unique_ptr<Command> CommandFactory::create(ParsedType &parse) const {

    if (parse.name == "cd") {
        return make_unique<CdCommand>(parse.args);
    }
    if (parse.name == "echo") {
        return make_unique<EchoCommand>(parse.args);
    }
    if (parse.name == "pwd") {
        return make_unique<PwdCommand>(parse.args);
    }
    if (parse.name == "export") {
        return make_unique<ExportCommand>(parse.args);
    }
    if (parse.name == "unset") {
        return make_unique<UnsetCommand>(parse.args);
    }
    if (parse.name == "exit") {
        return make_unique<ExitCommand>(parse.args);
    }

    // Internal Command

   return make_unique<InternalCommand>(parse.name,parse.args);


}
