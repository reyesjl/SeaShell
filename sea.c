#include <stdlib.h>
#include "sea_loop.h"

int main(int argc, char **argv) {
    // Pre-startup if needed...

    // Run prompt loop.
    sea_loop();

    // Clean up
    return EXIT_SUCCESS;
}