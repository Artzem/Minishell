#include <unistd.h>
#include "CdCommand.h"
#include "Command.h"


CdCommand::CdCommand(vector<string>args,ostream& out):BuiltinCommand(move(args)) {

}

//  Logic for the Cd Command
int CdCommand::execute() {

    int result = chdir(args_[0].c_str());

    if (result == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

