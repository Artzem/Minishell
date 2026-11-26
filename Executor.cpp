#pragma once
#include "parser.h"
#include "Executor.h"

// For OS calls
#include <fcntl.h>
#include <unistd.h>


int Executor::run(Command& command,ParsedType& parse) const {

    if (parse.isOutput) {
        // logic for >


        int saved = dup(1);

        int df = open(parse.filePath.c_str(),O_RDWR | O_CREAT| O_TRUNC,0644);
        // eror check
        if (df == -1) {return -1; }

        //action
        dup2(df,1);
        command.execute();

        // cleanup
        dup2(saved,1);
        close(df);
        close(saved);
    }

    if (parse.isOutputEnd) {
        //   logic for >>
        int saved = dup(1);

        int df = open(parse.filePath.c_str(),O_RDWR | O_CREAT | O_APPEND,0644);

        // eror check
        if (df == -1) {return -1; }

        //execute
        dup2(df,1);
        command.execute();

        // cleanup
        dup2(saved,1);
        close(df);
        close(saved);
    }


   if (parse.isInput) {
    //   logic for <
       int saved = dup(0);

       int df = open(parse.filePath.c_str(),O_RDONLY);

       if (df == -1) { return -1;}

       dup2(df,0);
     int status =  command.execute();

       dup2(saved,0);
       close(df);
       close(saved);
       return status;

   }


   if (parse.isPipe) {
     //   maybe logic for |
   }




    return command.execute();
}
