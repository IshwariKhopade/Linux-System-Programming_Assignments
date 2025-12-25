/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment3_2.c
//  Description : Accept Directory & file Name from user, check if file exists in that directory & print absolute path if found.
//  Author : Ishwari Bharat Khopade
//  Date : 25/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int ChkFilePresent(char *DirName, char *FileName)
{
    DIR *dp = NULL;
    struct dirent *dobj = NULL;

    dp = opendir(DirName);
    if (dp == NULL)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }

    while((dobj = readdir(dp)) != NULL)
    {
        char path[1024];

        sprintf(path, "%s/%s", DirName, dobj->d_name);      //to combine absolute path & file Name

        if(strcmp(dobj->d_name,FileName) == 0)
        {
            printf("File found with path : %s\n", path);
            return 1;
        }
    }

    closedir(dp);
    return 0;
}

int main()
{
    char DirName[100];
    char FileName[100];
    int iRet = 0;
    
    printf("Enter Directory Name (Absolute path): \n");
    scanf("%s", DirName);

    printf("Enter File Name to search: \n");
    scanf("%s", FileName);

    iRet = ChkFilePresent(DirName, FileName);

    if (iRet == -1)
    {
        printf("Unable to open Directory.\n");
    }
    else if (iRet == 0)
    {
        printf("File not found.\n");
    }

    return 0;
}