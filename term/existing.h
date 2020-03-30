#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// existing shell commands
int sea_cd(char **args);
int sea_help(char **args);
int sea_exit(char **args);

// the commands with the corresponding function
char *existing_str[] = {                                          // existing names of system calls
  "cd",                                                           // check these in sea_execute with strcmp()
  "help",
  "exit"
};

int (*existing_func[]) (char **) = {                              // corresponding functions.
  &sea_cd,
  &sea_help,
  &sea_exit
};

// size of all the existing functions
int sea_num_existing() {
  return sizeof(existing_str) / sizeof(char *);
}

// existing change directory command
int sea_cd(char **args)
{
  if (args[1] == NULL) {                                            // cd arguments not enough
    fprintf(stderr, "sea: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {                                      // call chdir()
      perror("sea: with cd command");                               // handle error
    }
  }
  return 1;                                                         // ran well.
} 

// help command
int sea_help(char **args)
{
  int i;
  printf("SEA SHELL a.k.a C Shell\n");                             // handle a help command
  printf("Its a semi-full functioning terminal!\n");
  printf("The following are built in:\n");

  for (i = 0; i < sea_num_existing(); i++) {                       // print out the existing commands.
    printf("  %s\n", existing_str[i]);
  }

  return 1;
}

// exit command
int sea_exit(char **args)                                           // exit command
{
  return 0;
}