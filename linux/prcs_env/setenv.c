// setenv.c - set env var
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char * p;
    p = getenv("HOME");
    if (p == NULL) {
        perror("fail to getenv");
        exit(1);
    }
    printf("$HOME is %s\n", p);
    if (setenv("HOME", "/home/admin", 0) == -1) {
        perror("fail to setenv");
        exit(1);
    }
    p = getenv("HOME");
    if (p == NULL) {
        perror("fail to getenv");
        exit(1);
    }

    printf("$HOME is %s\n", p);
    if (setenv("HOME", "/home/admin", 1) == -1) {
        perror("fail to set env");
        exit(1);
    }

    p = getenv("HOME");
    if (p == NULL) {
        perror("fail to getenv");
        exit(1);
    }
    printf("$HOME is %s\n", p);

    return 0;
}
