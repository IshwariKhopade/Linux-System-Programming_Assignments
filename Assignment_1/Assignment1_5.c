/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment1_5.c
//  Description : Accept file name & number of bytes from user and read n bytes using read(), Display it one console.
//  Author : Ishwari Bharat Khopade
//  Date : 22/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

int ReadFile(char *fName, int n)
{
    int fd = 0, iRet = 0;
    char Buffer[100] = {'\0'};

    fd = open(fName, O_RDONLY);
    if(fd < 0)
    {
        printf("Unable to open file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    iRet = read(fd, Buffer, n);
    printf("Data from file: %s \n", Buffer);

    close(fd);
    return iRet;
}
int main()
{
    char fName[100];
    int n = 0, iRet1 = 0;
    
    printf("Enter Name of file you want to open : \n");
    scanf("%s", fName);

    printf("Enter number of bytes you want to read : \n");
    scanf("%d", &n);

    iRet1 = ReadFile(fName, n);
    printf("%d bytes gets successfully read from file\n", iRet1);

    return 0;
}