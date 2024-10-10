#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("ERROR: Please enter a filename.\n");
        return 1;
    }

    else if (argc > 2) {
        printf("ERROR: Too many arguments.\n");
        return 1;
    }

    else {
        printf("TEST MESSAGE: File entered.\n");
        // opens file for reading
        FILE *file = fopen(argv[1], "r");

        // keeps track of ultimate & penultimate lines
        char *last_line1 = NULL;
        char *last_line2 = NULL;

        /*
        initializes variables needed for getline() function]
        (next_line) checks if end of file has been reached
        (getline()) returns -1 after reaching end of file
        */
        char *line = NULL;
        unsigned int len = 0;
        int read;

        // loops until reaching end of file
        while ((read = getline(&line, (size_t *)&len, file)) != -1) {

            if (last_line2) {
                free(last_line2);
            }

            // only update strings if not at end of file yet
            last_line2 = last_line1;
            last_line1 = strdup(line);

        }

        /*
        only print second line if there is > 1 line
        (always prints atleast 1 line)
        */
        if (last_line2) {
            printf("%s", last_line2);
        }
        if (last_line1) {
            printf("%s", last_line1);
        }

        // frees up used memory
        free(last_line1);
        free(last_line2);
        free(line);
        fclose(file);
        
    }

    return 0;
}