////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment3_4.c
//  Description : Accept Directory name & delete files with size = 0bytes (regular files only). Print file names deleted + total deleted count
//  Author : Ishwari Bharat Khopade
//  Date : 25/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int DeleteFiles(char *DirName)
{
    DIR *dp = NULL;
    struct stat sobj;
    struct dirent *dobj = NULL;
    int count = 0;

    dp = opendir(DirName);
    if (dp == NULL)
    {
        printf("Cannot open Directory : %s\n", strerror(errno));
        return -1;
    }

    while((dobj = readdir(dp)) != NULL)
    {
        char path[1024];

        sprintf(path, "%s/%s", DirName, dobj->d_name);  // combine absolute path & file name

        if((stat(path, &sobj)) < 0)
        {
            printf("Unable to get stat info for %s\n", path);
            continue;
        }

        if(S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            if(unlink(path) == 0)  
            {
                printf("Deleted: %s\n", path);
                count++;
            }
            else
            {
                printf("Unable to delete %s : %s\n", path, strerror(errno));
            }
        }
    }

    closedir(dp);

    printf("Total 0 size files deleted: %d\n", count);
    return count;
}

int main()
{
    char DirName[100];
    int iRet = 0;
    
    printf("Enter Directory Name (Absolute path): \n");
    scanf("%s", DirName);

    iRet = DeleteFiles(DirName);

    return 0;
}
