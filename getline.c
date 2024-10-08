#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("ERROR: Please enter a filename.\n");
    }

    else if (argc > 2) {
        printf("ERROR: Too many arguments.\n");
    }

    else {
        printf("TEST MESSAGE: File entered.\n");
        // opens file for reading
        FILE *file = fopen(argv[1], "r");

        // keeps track of ultimate & penultimate lines
        char *prev_line;
        char *current_line;

        /*
        initializes variables needed for getline() function]
        (next_line) checks if end of file has been reached
        (getline()) returns -1 after reaching end of file
        */
        char *next_line;
        size_t next_n = 0;
        int end = 0;

        /*
        keeps track of if there is 1 or more lines
        (determines whether 1 or 2 lines are printed)
        */
        int lines = 0;

        // loops until reaching end of file
        while (end != -1) {

            // only update strings if not at end of file yet
            if ((end = getline(&next_line, &next_n, file)) != -1) {
                prev_line = strdup(current_line);
                current_line = strdup(next_line);
                lines++;
            }

        }

        /*
        only print second line if there is > 1 line
        (always prints atleast 1 line)
        */
        if (lines > 1) {
            printf("%s", prev_line);
        }
        printf("%s\n", current_line);

        // frees up used memory
        if (lines >= 1) {
            free(current_line);
        }
        if (lines > 1) {
            free(prev_line);
        }
        free(file);
        
    }

    return 0;
}