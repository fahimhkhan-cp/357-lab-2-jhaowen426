#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    // iterates through each argument
    for (int i = 1; i < argc; i++) {

        // print argument if argument begins with '-'
        if (argv[i][0] == '-')  {
            printf("%s\n", argv[i]);
        }

    }

    return 0;
}