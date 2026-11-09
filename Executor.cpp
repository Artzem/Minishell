#include "Executor.h"

int Executor::run(Command& command) const {
    return command.execute();
}
