
#include <unistd.h>
#include "PwdCommand.h"
#include <iostream>
using namespace std;


//Call .h   // call constructor             // parent class and  pass "args" that becomes "args_"
PwdCommand::PwdCommand(vector<string> args):BuiltinCommand(std::move(args)) {

}
// logic for the code
int PwdCommand::execute() {

    char buffer[PATH_MAX];
    
    if (getcwd(buffer,PATH_MAX)!= NULL) {
        cout << "Current Working Directory: " << buffer<< endl;
    }
    else {
        cerr <<"Error Getting Directory" << endl;
    }

    return 0;
}
