/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment3_1.c
//  Description : Accept source file & destination file, copy using read()/write(),preserve permissiona(stat()+chmod()).
//  Author : Ishwari Bharat Khopade
//  Date : 25/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int CopyFile(char *src_file, char *dest_file)
{
    int fd1 = 0, fd2 = 0;
    int iRet1 = 0, iRet2 = 0;
    char Buffer[100];
    struct stat sobj;

    fd1 = open(src_file, O_RDONLY);
    if(fd1 < 0)
    {
        printf("Unable to open Source file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    //get src file info
    if((stat(src_file, &sobj)) < 0 )
    {
        printf("Unable to get stat information");
        return -1;
    }

    fd2 = open(dest_file, O_WRONLY | O_TRUNC | O_CREAT, sobj.st_mode);
    if(fd2 < 0)
    {
        printf("Unable to open Destination file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    //Read data from src & write into dest
    while((iRet1 = read(fd1, Buffer, sizeof(Buffer))) > 0)
    {
        iRet2 = write(fd2, Buffer, iRet1);
        if (iRet2 < 0)
        {
            printf("Write error\n");
            close(fd1);
            close(fd2);
            return -1;
        }
    }

    printf("Source file contents copied succesfully in Destination file\n");

    //Apply permission
    chmod(dest_file, sobj.st_mode);
    
    close(fd1);
    close(fd2);

    return 0;
}

int main()
{
    char src_file[100]; 
    char dest_file[100]; 
    int iRet = 0;
    
    printf("Enter Source file Name: \n");
    scanf("%s", src_file);

    printf("Enter Destination file Name: \n");
    scanf("%s", dest_file);

    iRet = CopyFile(src_file, dest_file);

    if (iRet == -1)
    {
        printf("Unable to Copy Source File into Destination File.\n");
    }

    return 0;
}