#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("ERROR: Please enter a filename.");
    }

    else if (argc > 2) {
        printf("ERROR: Too many arguments.");
    }
    
    else {
        FILE *file = ("%s", argv[1], "r");
    }

    return 0;
}