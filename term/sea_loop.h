#include <stdio.h>
#include <stdlib.h>
#include "../line/sea_read_line.h"
#include "../line/sea_split_line.h"
#include "../run/sea_execute.h"
#include "existing.h"

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

//  Decides to run an existing system function,
//  or a custom command.
int sea_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < sea_num_existing(); i++) {
    if (strcmp(args[0], existing_str[i]) == 0) {
      return (*existing_func[i])(args);
    }
  }

  return sea_launch(args);
}