#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 512

int main(int argc, char **argv)
{
    int from, to, nr, nw, n;
    char buf[BUFSIZE];

    if ((from = open(argv[1], O_RDONLY)) < 0)
    {
        perror("Error opening source file");
        exit(1);
    }

    if ((to = creat(argv[2], 0666)) < 0)
    {
        perror("Error creating destination file");
        exit(1);
    }

    while ((nr = read(from, buf, sizeof(buf))) != 0)
    {
        if (nr < 0)
        {
            perror("Error reading source file");
            exit(1);
        }
        nw = 0;
        do
        {
            if ((n = write(to, &buf[nw], nr - nw)) < 0)
            {
                perror("Error writing destination file");
                exit(1);
            }
            nw += n;
        } while (nw < nr);
    }
    close(from);
    close(to);
}
