cmake_minimum_required(VERSION 4.3)
project(Shell)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shell
        main.cpp
        shell.cpp
        parser.cpp
        Executor.cpp
        CommandFactory.cpp
        CdCommand.cpp
        PwdCommand.cpp
)
