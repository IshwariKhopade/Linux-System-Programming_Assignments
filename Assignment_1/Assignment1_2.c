/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment1_2.c
//  Description : Open file by accepting file name & mode from user, convert modes to flags & display fd.
//  Author : Ishwari Bharat Khopade
//  Date : 20/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

//This function converts mode to flags & returns a flag
int ModeToFlag(char fMode)
{
    switch(fMode)
    {
        case 'R':
            return O_RDONLY;

        case 'W':
            return O_WRONLY | O_CREAT;

        case 'A':
            return O_WRONLY | O_APPEND | O_CREAT;
        
        default:
            return -1;
    }
}

//This function opens file 
int FileOpen(char *fName, int flag)
{
    int fd = 0;

    fd = open(fName, flag, 0777);

    if(fd == -1)
    {
        perror("Unable to open file");
    }
    return fd;
}

int main()
{
    char fName[100];
    char fMode;
    int fd = 0;
    char flag = 0;
    
    printf("Enter Name of file you want to open : \n");
    scanf("%s", fName);

    printf("Enter mode (R / W / A) in which you want to open file : \n");
    scanf(" %c", &fMode);

    flag = ModeToFlag(fMode);
    if(flag == -1)
    {
        printf("Invalid mode\n");
        return 1;
    }

    fd = FileOpen(fName, flag);
    if(fd != -1)
    {
        printf("File opened successfully\n");
        printf("Value of File Descriptor : %d\n", fd);

        close(fd);
    }

    return 0;
}