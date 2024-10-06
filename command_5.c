#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // initializes comparison condition "-"
    char s1[2] = "-";
    char* s2;

    for (int i = 1; i < argc; i++) {
        // take stdin one argument at a time
        s2 = argv[i];

        // print argument if argument begins with "-"
        if (s2[0] == s1[0])  {
            printf("%s\n", s2);
        }

    }

    return 0;
}