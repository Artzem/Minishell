#include <unistd.h>
#include "CdCommand.h"



// logic of the code
int CdCommand::execute() {

    int result = chdir(args[0].c_str());

    if (result == 0) {
        return 0;
    }
    else {
        return -1;
    }


}

