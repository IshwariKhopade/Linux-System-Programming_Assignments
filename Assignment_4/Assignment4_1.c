///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment4_1.c
//  Description : Write program thst copies content of one file into another. accept src file name and destination file name as command line argument
//  Author : Ishwari Bharat Khopade
//  Date : 02/01/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

int copyFile(const char *src_file, const char *dest_file)
{
    int fd1 = 0, fd2 = 0;
    int iRet1 = 0, iRet2 = 0;
    char buffer[BUFFER_SIZE];

    fd1 = open(src_file, O_RDONLY);
    if(fd1 < 0)
    {
        printf("Unable to open Source file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    fd2 = open(dest_file, O_WRONLY | O_TRUNC | O_CREAT , 0644);
    if(fd2 < 0)
    {
        printf("Unable to open Destination file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    //Read data from src & write into dest
    while((iRet1 = read(fd1, buffer, BUFFER_SIZE)) > 0)
    {
        iRet2 = write(fd2, buffer, iRet1);
        if (iRet2 < 0)
        {
            printf("Write error\n");
            close(fd1);
            close(fd2);
            return -1;
        }
    }

    printf("Source file contents copied succesfully in Destination file\n");
    
    close(fd1);
    close(fd2);

    return 0;
    
}

int main(int argc, char *argv[])
{
    int iRet = 0;

    if(argc != 3)
    {
        printf("Enter : %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    iRet = copyFile(argv[1], argv[2]);

    if (iRet == -1)
    {
        printf("Unable to Copy Source File into Destination File.\n");
    }

    return 0;
}
