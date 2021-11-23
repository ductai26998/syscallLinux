#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char buf1[] = "LAB ss";
char buf2[] = "OS Linux";

// exit(0) to exit a successfully process
// exit(1) to exit a error process
int main(void)
{
    int fd;
    if ((fd = creat("file.txt", S_IRWXU)) < 0)
    {
        perror("Creation error");
        exit(1);
    }

    if (write(fd, buf1, sizeof(buf1)) < 0)
    {
        perror("Writing error");
        exit(1);
    }

    // Concat buf2 after buf1 
    if (lseek(fd, sizeof(buf1), SEEK_SET) < 0)
    {
        perror("Positioning error");
        exit(1);
    }

    if (write(fd, buf2, sizeof(buf2)) < 0)
    {
        perror("Writing error");
        exit(1);
    }
}
