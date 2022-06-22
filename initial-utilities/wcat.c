#include <stdio.h>

int main(int argc, char *argv[]) {
    int code = 0;
    for (int i = 1; i < argc; ++i) {
        FILE *fp;
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            code = 1;
            printf("%s: %s: No such file or directory\n", argv[0], argv[i]);
        } else {
            char buffer[255];
            while (fgets(buffer, 255, fp)) {
                printf("%s", buffer);
            }
        }
    }
    return code;
}
