
#include "CommandFactory.h"
#include "CdCommand.h"
#include "Command.h"
#include "EchoCommand.h"
#include "PwdCommand.h"
#include "ExternalCommand.h"
#include <iostream>
#include<unistd.h>
#include <cstdlib>
using namespace std;


unique_ptr<Command> CommandFactory::create(ParsedType &parse) const {

    if (parse.name == "cd") {
        return make_unique<CdCommand>(parse.args);
    }
     if(parse.name == "echo") {
         return make_unique<EchoCommand>(parse.args);
     }
    if (parse.name == "pwd") {
    return make_unique<PwdCommand>(parse.args);
    }
    // if (parse.name == "export") {
    //     return make_unique<ExportCommand>(parse.args);
    // }
    // if (parse.name == "unset") {
    //     return make_unique<UnsetCommand>(parse.args);
    // }
    // if (parse.name == "exit") {
    //     return make_unique<ExitCommand>(parse.args);
    // }

    // Internal Command Logic Here
    else {
       return make_unique<ExternalCommand>(parse.name,parse.args);

    }


   // return make_unique<InternalCommand>(parse.name,parse.args);
    return nullptr;



    // if "Jobs" Here?

}
