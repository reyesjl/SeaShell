#include <stdio.h>
#include <stdlib.h>

#define SEA_RL_BUFSIZE 1024

// read in line from seainal of unknown size.
// allocate a certain amount. If they exceed it,
// we will ask for more.
char *sea_read_line(void) {
    int bufsize = SEA_RL_BUFSIZE;                       // create buffer
    int index = 0;                                      // set index/position
    char *buffer = malloc(sizeof(char) * bufsize);      // allocate memory
    int c;                                              // current char

    // buffer couldn't be allocated for whatever reason.
    if (!buffer) {
        fprintf(stderr, "sea: allocation error in buffer\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read a single char
        c = getchar();

        // replace EOF will null char
        if (c == EOF || c == '\n') {                   // check EOF and newline
            buffer[index] = '\0';                      // set null seainated
            return buffer;                             // return line
        } else {
            buffer[index] = c;                         // same char
        }
        index++;                                       // move to next char

        // need more buffer :/
        if (index >= bufsize) {
            bufsize += SEA_RL_BUFSIZE;                // double buffer
            buffer = realloc(buffer, bufsize);         // reallocate memory
            
            // buffer couldn't be allocated for whatever reason.
            if (!buffer) {
                fprintf(stderr, "sea: re-allocation error in buffer\n");
                exit(EXIT_FAILURE);
            }
        }
    } // while

}