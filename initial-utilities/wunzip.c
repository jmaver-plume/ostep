#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        int amount;
        int ch;
        while (1) {
            if (!fread(&amount, sizeof (int), 1, fp)) break;
            fread(&ch, sizeof (char), 1, fp);
            for (int j = 0; j < amount; ++j) {
                printf("%c", ch);
            }
        }
    }
}