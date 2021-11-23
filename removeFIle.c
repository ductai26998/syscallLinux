#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd = remove(argv[1]);
    if (fd < 0) {
        perror("Error delete");
        exit(1);
    }
    return 0;
}