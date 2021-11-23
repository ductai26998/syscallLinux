#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd = rename(argv[1], argv[2]);
    if (fd < 0) {
        perror("Error rename");
        exit(1);
    }
    return 0;
}