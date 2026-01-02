///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment4_2.c
//  Description : Write program that copies a file from given file offset byte of given source file
//  Author : Ishwari Bharat Khopade
//  Date : 02/01/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

int CopyFileFromOffset(const char *src_file, const char *dest_file, off_t offset)
{
    int fd1 = 0, fd2 = 0;
    int iRet = 0;
    char buffer[BUFFER_SIZE];

    fd1 = open(src_file, O_RDONLY);
    if(fd1 < 0)
    {
        printf("Unable to open source file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }


    fd2 = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd2 < 0)
    {
        printf("Unable to open destination file\n");
        close(fd1);
        return -1;
    }

    // Set file offset
    if(lseek(fd1, offset, SEEK_SET) == -1)
    {
        printf("Invalid offset\n");
        close(fd1);
        close(fd2);
        return -1;
    }

    // Copy data from offset to end
    while((iRet = read(fd1, buffer, BUFFER_SIZE)) > 0)
    {
        write(fd2, buffer, iRet);
    }

    close(fd1);
    close(fd2);

    return 0;
}

int main(int argc, char *argv[])
{
    int iRet = 0;
    off_t offset;

    if(argc != 4)
    {
        printf("Enter: %s <source_file> <destination_file> <offset>\n", argv[0]);
        return 1;
    }

    sscanf(argv[3], "%ld", &offset);
    
    iRet = CopyFileFromOffset(argv[1], argv[2], offset);

    if(iRet == 0)
    {
        printf("File copied successfully from offset %ld bytes\n", offset);
    }
    else
    {
        printf("File copy failed\n");
    }

    return 0;
}
