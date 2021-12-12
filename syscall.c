#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 512

// exit(0) to exit a successfully process
// exit(1) to exit a error process

void createFile(char *filename)
{
    int fd;
    fd = creat(filename, S_IRWXU);
    if (fd < 0)
    {
        perror("\nError create file");
        // exit(1);
    }
    else
    {
        printf("\n %s was created successfully \n", filename);
    }
}

int openFile(char *filename)
{
    int fd;
    fd = open(filename, O_RDWR);
    if (fd != -1)
    {
        printf(" \n %s was opened \n ", filename);
    }
    else
    {
        perror("\nError open file");
    }
    return fd;
}

void readFile(char *filename)
{
    int fd, nr, nw, n;
    char buf[50];
    fd = openFile(filename);

    if (fd != -1)
    {
        if (read(fd, buf, sizeof(buf)) < 0)
        {
            perror("\nError read file");
        }
        else
        {
            close(fd);
            printf(" \n Content in %s is: \n %s \n ", filename, buf);
        }
    }
}

void writeFile(char *filename, char *text)
{
    int fd;
    fd = open(filename, O_RDWR);
    if (fd != -1)
    {
        write(fd, text, strlen(text));
        close(fd);
        printf(" \n %s was written \n ", filename);
        close(fd);
    }
    else
    {
        perror("\nError write file");
    }
}

void deleteFile(char *filename)
{
    int fd = remove(filename);
    if (fd < 0)
    {
        perror("\nError delete");
        // exit(1);
    }
    else
    {
        printf("%s was deleted\n", filename);
    }
}

void copyFile(char *fromFile, char *toFile)
{
    int from, to, n;
    char buf[BUFSIZE];

    if ((from = open(fromFile, O_RDONLY)) < 0)
    {
        perror("Error opening source file");
        // exit(1);
    }
    else if ((to = creat(toFile, S_IRWXU)) < 0)
    {
        perror("Error creating destination file");
        // exit(1);
    }
    else
    {
        n = read(from, buf, sizeof(buf));
        write(to, buf, n);
        close(from);
        close(to);
        printf("Copied");
    }
}

void renameFile(char *oldname, char *newname)
{
    int fd = rename(oldname, newname);
    if (fd < 0)
    {
        perror("Error rename");
        // exit(1);
    }
    else
    {
        printf("%s -> %s", oldname, newname);
    }
}

void menu()
{
    printf("\n------------------------------------\n");
    printf("\tFILE MANAGER");
    printf("\n------------------------------------\n");
    printf("\t0. Exit \n");
    printf("\t1. Create new file \n");
    printf("\t2. Open file \n");
    printf("\t3. Read file \n");
    printf("\t4. Write content to file \n");
    printf("\t5. Copy file \n");
    printf("\t6. Rename file \n");
    printf("\t7. Delete file \n");
    printf("\nPlease choose an option: ");
}

int main()
{
    int option;
    while (1)
    {
        menu();
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            exit(0);
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
            char filename[50];
            printf("File name: ");
            scanf("%s", filename);
            openFile(filename);
        }
        break;
        case 3:
        {
            char filename[50];
            printf("File name: ");
            scanf("%s", filename);
            readFile(filename);
        }
        break;
        case 4:
        {
            char filename[50];
            char text[300];
            printf("File name: ");
            scanf("%s", filename);
            read(0, text, 500);
            writeFile(filename, text);
        }
        break;
        case 5:
        {
            char fromFile[50];
            char toFile[50];
            printf("Copy from: ");
            scanf("%s", fromFile);
            printf("Into: ");
            scanf("%s", toFile);
            copyFile(fromFile, toFile);
        }
        break;
        case 6:
        {
            char oldName[50];
            char newName[50];
            printf("Old name: ");
            scanf("%s", oldName);
            printf("New name (Can not have space): ");
            scanf("%s", newName);
            renameFile(oldName, newName);
        }
        break;
        case 7:
        {
            char filename[50];
            printf("File name: ");
            scanf("%s", filename);
            deleteFile(filename);
        }
        break;
        default:
            printf("Option is invalid");
            break;
        }
    }

    return 0;
}