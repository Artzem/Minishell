#include <vector>
using namespace std;

class Command {

public:

    // constructor
    // explicit (for error checks)
    explicit Command(vector<string>args): args_(move(args)){};
                    //   Command(args); args --> args_ (a permanent data space)

    // destructor
    virtual ~Command() = default;

    // default 'execute'
    virtual int execute() = 0;
    // default 'name' (dont need to use?)
    virtual string name() const = 0;


private:

    // why make it private
    vector<string> args_;

};

class BuiltinCommand: public Command {
public:
    // We can use "Commands" constructor
    using Command::Command;
};

// // Commands included by the OS, but we need to make a path to use  them
// class InternalCommand: public Command {
//
// public:
//     // We can use "Commands" constructor
//     using Command:: Command;
//
// };


