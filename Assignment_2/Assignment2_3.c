/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment2_3.c
//  Description : Accept Directory name from user and & list all files from that Directory.
//  Author : Ishwari Bharat Khopade
//  Date : 23/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>

int DirList(char *DirName)
{
    DIR *dp = NULL;
    struct dirent *dobj = NULL;

    dp = opendir(DirName);

    if (dp == NULL)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("Directory opened succesfully!\n");
    }

    printf("Files in %s Directory : \n", DirName);

    while((dobj = readdir(dp)) != NULL)
    {
        printf(" %s \n", dobj->d_name);
    }
    
    closedir(dp);
    return 0;
}

int main()
{
    char DirName[100];
    int iRet = 0;
    
    printf("Enter Directory Name (Absolute path): \n");
    scanf("%s", DirName);

    iRet = DirList(DirName);

    if (iRet == -1)
    {
        printf("Unable to list directory contents.\n");
    }

    return 0;
}