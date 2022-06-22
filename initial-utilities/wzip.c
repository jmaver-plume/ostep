#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void write_char (int counter, char ch) {
    int x[1] = { counter };
    fwrite(x, sizeof(counter), 1, stdout);

    char y[1] = { ch };
    fwrite(y, sizeof(y), 1, stdout);
}

int main(int argc, const char *argv[]) {
    if (argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char last = '\0';
    int counter = 1;
    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        char *line = NULL;
        size_t linecap = 0;
        while (getline(&line, &linecap, fp) != -1) {
            for (int i = 0; i < strlen(line); ++i) {
                if (line[i] == last) {
                    counter++;
                } else {
                    if (last != '\0') {
                        int x[1] = { counter };
                        fwrite(x, sizeof(counter), 1, stdout);

                        char y[1] = { last };
                        fwrite(y, sizeof(y), 1, stdout);
                    }
                    last = line[i];
                    counter = 1;
                }
            }
        }
    }

    int x[1] = { counter };
    fwrite(x, sizeof(counter), 1, stdout);

    char y[1] = { last };
    fwrite(y, sizeof(y), 1, stdout);

    return 0;
}