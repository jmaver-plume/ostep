#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void grep_file(FILE *fp, const char search[]) {
    if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    char *line = NULL;
    size_t linecap = 0;
    while (getline(&line, &linecap, fp) != -1) {
        if (strstr(line, search) != NULL) {
            printf("%s", line);
        }
    }
}

int main(int argc, const char *argv[]) {
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc > 2) {
        for (int i = 2; i < argc; ++i) {
            FILE *fp = fopen(argv[i], "r");
            grep_file(fp, argv[1]);
        }
    } else {
        grep_file(stdin, argv[1]);
    }

    return 0;
}