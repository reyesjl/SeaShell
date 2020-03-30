#include <stdio.h>
#include <stdlib.h>
#include "line/sea_read_line.h"
#include "line/sea_split_line.c"
#include "run/sea_execute.c"

// Prompt loop
void sea_loop(void) {
    char *line;
    char **args;
    int status;

    // Prompt user for input and process lines
    do {
        printf("sea@sandyhost>$ ");        // prompt
        line = sea_read_line();             // read line
        args = sea_split_line(line);        // parse line into arguments
        status = sea_execute(args);         // run process
    } while (status);
}