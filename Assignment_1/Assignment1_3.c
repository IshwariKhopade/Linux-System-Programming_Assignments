/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment1_3.c
//  Description : Open file by accepting file name & mode from user & check file access permission
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
            return R_OK;

        case 'W':
            return W_OK;

        case 'E':
            return X_OK;
        
        default:
            return -1;
    }
}

//This function checks file access permission
void FileAccess(char *fName, int flag)
{
    if(access(fName, flag) == 0)
    {
        printf("Accessible\n");
    }
    else
    {
        printf("Not Accessible\n");
    }
}

int main()
{
    char fName[100];
    char fMode;
    char flag = 0;
    
    printf("Enter Name of file : \n");
    scanf("%s", fName);

    printf("Enter permission (for Read-R | Write-W | Execute-E ) to check the Accessibilty of file : \n");
    scanf(" %c", &fMode);

    flag = ModeToFlag(fMode);
    if(flag == -1)
    {
        printf("Invalid mode\n");
        return 1;
    }

    FileAccess(fName, flag);

    return 0;
}