/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment1_1.c
//  Description : Open file by accepting file name from user & handle errors using perror()
//  Author : Ishwari Bharat Khopade
//  Date : 20/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int FileOpen(char *fName)
{
    int fd = 0;

    fd = open(fName, O_RDONLY);

    if(fd == -1)
    {
        perror("Unable to open file");
    }
    return fd;
}

int main()
{
    char fName[100];
    int fd = 0;
    
    printf("Enter Name of file you want to open : \n");
    scanf("%s", fName);

    fd = FileOpen(fName);

    if(fd != -1)
    {
        printf("File opened successfully\n");
        printf("Value of File Descriptor : %d\n", fd);

        close(fd);
    }

    return 0;
}