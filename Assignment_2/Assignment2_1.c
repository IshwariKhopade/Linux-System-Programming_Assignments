/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment2_1.c
//  Description : Accept file name from user and read whole file using read(), Display it one console.
//  Author : Ishwari Bharat Khopade
//  Date : 23/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

int ReadFile(char *fName)
{
    int fd = 0, iRet = 0;
    char Buffer[100] = {'\0'};
    int iRetTotal = 0;

    fd = open(fName, O_RDONLY);
    if(fd < 0)
    {
        printf("Unable to open file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
    printf("Data from file : \n");
    while((iRet = read(fd, Buffer, sizeof(Buffer)))> 0)
    {
        printf("%.*s",(int)iRet, Buffer);
        iRetTotal = iRetTotal + iRet;
    }
    close(fd);
    return iRetTotal;
}

int main()
{
    char fName[100];
    int iRet1 = 0;
    
    printf("Enter Name of file you want to read : \n");
    scanf("%s", fName);

    iRet1 = ReadFile(fName);
    printf("\n %d bytes gets successfully read from file \n", iRet1);

    return 0;
}