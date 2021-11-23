#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void createFile(char *filename)
{
    creat(filename, S_IRWXU);
    printf("\n %s was created successfully \n", filename);
}

void openFile(char *filename)
{
    int fd;
    fd = open(filename, O_RDWR);
    if (fd != -1)
    {
        printf(" \n %s was opened \n ", filename);
    }
    else
    {
        printf("\n Error \n");
    }
}

void readFile(char *filename)
{
    int fd;
    char buf[50];
    fd = open(filename, O_RDONLY);
    if (fd != -1)
    {
        read(fd, buf, 100);
        close(fd);
        printf(" \n Content in %s is: \n %s \n ", filename, buf);
    }
    else
    {
        printf("\n Error \n");
    }
}

void writeFile(char *filename)
{
    char text[] = "hhu hihu gdgd";
    int fd;
    fd = open(filename, O_RDWR);
    if (fd != -1)
    {
        write(fd, text, sizeof(text));
        close(fd);
        printf(" \n %s was written \n ", filename);
    }
    else
    {
        printf("\n Error \n");
    }
}

// void openFile() {
//     int fd;
//     char buffer[100];
//     char text[50] = "Hello Tai nha";
//     char filename[50] = "test1.txt";
//     fd = open(filename, O_RDWR);
//     printf("fd = %d", fd);
//     if (fd != -1) {
//         printf("\n %s opened", filename);
//         write(fd, text, sizeof(text));
//         lseek(fd, 0, SEEK_SET);
//         read(fd, buffer, sizeof(text));
//         printf("\n %s was written to %s", buffer, filename);
//         close(fd);
//     } else {
//         createFile(filename);
//     }
//     // return 0;
// }

void menu()
{
    printf("\n\nPlease choose a option: \n");
    printf("0. Exit \n");
    printf("1. Create new file \n");
    printf("2. Open file \n");
    printf("3. Read file \n");
    printf("4. Write \n");
}

int main()
{
    // openFile();
    // createFile("sss.txt");
    char filename[] = "ndt.txt";
    int option;
    while (1)
    {
        menu();
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            break;
        case 1:
        {
            char filename[50];
            printf("File name: ");
            scanf("%s", filename);
            createFile(filename);
        }
        break;
        case 2:
        {
            // char filename[50];
            // printf("File name: ");
            // read(0, filename, strlen(filename));
            openFile(filename);
        }
            break;
        case 3:
            readFile(filename);
            break;
        case 4:
        {
            writeFile("test1.txt");
        }
        break;
        default:
            break;
        }
    }

    return 0;
}