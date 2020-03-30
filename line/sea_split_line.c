#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEA_TOKEN_BUFSIZE 64
#define SEA_TOKEN_DELIM " \t\r\n\a"

// split the line into individual tokens to get commands.
char **sea_split_line(char *line) {
    int bufsize = SEA_TOKEN_BUFSIZE;                                // create buffer
    int index = 0;                                                  // set index/position
    char **tokens = malloc(sizeof(char*) * bufsize);                // allocate memory for array of tokens!
    char *token;                                                    // create pointer to each token/word/command

    // buffer couldn't be allocated for whatever reason.
    if (!tokens) {                                  
        fprintf(stderr, "sea: allocation error in tokens\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, SEA_TOKEN_DELIM);                          // now we split! yay!
    while(token != NULL) {
        tokens[index] = token;
        index++;                                                    // move to next token

        // need to reallocate memory :/
        if(index >= bufsize) {
            bufsize += SEA_TOKEN_BUFSIZE;                           // double buffer
            tokens = realloc(tokens, sizeof(char*) * bufsize);      // reallocate with new size

            // buffer couldn't be allocated for whatever reason.
            if (!tokens) {                                  
                fprintf(stderr, "sea: allocation error in tokens\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, SEA_TOKEN_DELIM);                      // find next token/word/command
    }

    tokens[index] = NULL;                                           // end of all tokens marked by null
    return tokens;                                                  // return array of tokens
}