/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment2_2.c
//  Description : Accept file name & String from user and write it in file using write(),print number of bytes written.
//  Author : Ishwari Bharat Khopade
//  Date : 23/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

int writeFile(char *fName, char *str)
{
    int fd = 0;
    int iRet = 0;

    fd = open(fName, O_WRONLY | O_APPEND);
    if(fd < 0)
    {
        printf("Unable to open file\n");
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
    
    iRet = write(fd, str, strlen(str));
    
    close(fd);
    return iRet;
}

int main()
{
    char fName[100];
    int iRet1 = 0;
    char str[100];
    
    printf("Enter Name of file: \n");
    scanf("%s", fName);

    printf("Enter String you want to write into file : \n");
    scanf(" %[^\n]", str);

    iRet1 = writeFile(fName, str);

    printf("\n %d bytes gets successfully written in file \n", iRet1);

    return 0;
}