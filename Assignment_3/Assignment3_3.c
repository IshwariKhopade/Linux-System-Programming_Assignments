//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment3_3.c
//  Description : Accept Source Directory & Destination Directory from user, move regular files (rename() if same filesystem else copy+delete)
//                & print count of moved files.
//  Author : Ishwari Bharat Khopade
//  Date : 25/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int MoveDir(char *SrcDirName, char *DestDirName)
{
    DIR *dp = NULL;
    int iRet1 = 0;
    struct stat sobj;
    struct dirent *dobj = NULL;
    int count = 0;

    dp = opendir(SrcDirName);
    if (dp == NULL)
    {
        printf("Cannot open Source Directory : %s\n", strerror(errno));
        return -1;
    }

    while((dobj = readdir(dp)) != NULL)
    {
        char srcpath[1024];
        char destpath[1024];
        int fd1 = 0, fd2 = 0;
        char Buffer[1024]; 

        sprintf(srcpath, "%s/%s", SrcDirName, dobj->d_name);      // combine absolute srcpath & file Name
        sprintf(destpath, "%s/%s", DestDirName, dobj->d_name);    // combine absolute destpath & file Name

        if((stat(srcpath, &sobj)) < 0)
        {
            printf("Unable to get stat info for %s\n", srcpath);
            continue;
        }

        if(S_ISREG(sobj.st_mode))
        {
            if(rename(srcpath, destpath) == 0)
            {
                count++;
            }
            else if(errno == EXDEV) // for different filesystem
            {
                fd1 = open(srcpath, O_RDONLY);
                fd2 = open(destpath, O_WRONLY | O_CREAT | O_TRUNC, sobj.st_mode);
                if(fd1 == -1 || fd2 == -1)
                {
                    printf("Error opening files\n");
                    if(fd1 != -1) 
                    {
                        close(fd1);
                    }
                    if(fd2 != -1) 
                    {
                        close(fd2);
                    }
                    continue;
                }

                while((iRet1 = read(fd1, Buffer, sizeof(Buffer))) > 0)
                {
                    write(fd2, Buffer, iRet1);
                }
                close(fd1);
                close(fd2);
                unlink(srcpath);  // delete original file
                count++;
            }
            else
            {
                printf("Unable to move %s : %s\n", srcpath, strerror(errno));
            }
        }
    }

    closedir(dp);

    printf("Total files moved: %d\n", count);
    return count;
}

int main()
{
    char SrcDirName[100];
    char DestDirName[100];
    int iRet = 0;
    
    printf("Enter Source Directory Name (Absolute path): \n");
    scanf("%s", SrcDirName);

    printf("Enter Destination Directory Name (Absolute path): \n");
    scanf("%s", DestDirName);

    iRet = MoveDir(SrcDirName, DestDirName);

    return 0;
}
