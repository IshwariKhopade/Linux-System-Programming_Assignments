///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment4_3.c
//  Description : Write program that copies a file using pread() & pwrie() without changing file offset
//  Author : Ishwari Bharat Khopade
//  Date : 02/01/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 100

int CopyFileFromOffset(const char *src_file, const char *dest_file, off_t offset)
{
    int fd_src = 0, fd_dest = 0;
    int iRet = 0;
    char Buffer[BUFFER_SIZE];

    fd_src = open(src_file, O_RDONLY);
    if(fd_src < 0)
    {
        printf("Unable to open source file: %s\n", strerror(errno));
        return 1;
    }

    fd_dest = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_dest < 0)
    {
        printf("Unable to open destination file: %s\n", strerror(errno));
        close(fd_src);
        return 1;
    }

    off_t curOffset = offset;

    while((iRet = pread(fd_src, Buffer, BUFFER_SIZE, curOffset)) > 0)
    {
        int written = 0;
        while(written < iRet)
        {
            int iWrite = pwrite(fd_dest, Buffer + written, iRet - written, curOffset + written);
            if(iWrite < 0)
            {
                printf("Error writing file: %s\n", strerror(errno));
                close(fd_src);
                close(fd_dest);
                return 1;
            }
            written += iWrite;
        }
        curOffset += iRet;
    }

    if(iRet < 0)
    {
        printf("Error reading source file: %s\n", strerror(errno));
        close(fd_src);
        close(fd_dest);
        return 1;
    }

    close(fd_src);
    close(fd_dest);

    return 0;
}

int main(int argc, char *argv[])
{
    int iRet = 0;
    off_t offset = 0;

    if(argc != 4)
    {
        printf("Usage: %s <source_file> <destination_file> <offset>\n", argv[0]);
        return 1;
    }

    sscanf(argv[3], "%ld", &offset);

    iRet = CopyFileFromOffset(argv[1], argv[2], offset);

    if(iRet == 0)
        printf("File copied successfully from offset %ld\n", offset);
    else
        printf("File copy failed\n");

    return 0;
}
