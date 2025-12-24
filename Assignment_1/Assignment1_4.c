/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Assignment1_4.c
//  Description : Accept file name & display file metadata using stat().
//  Author : Ishwari Bharat Khopade
//  Date : 22/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <time.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

void Display(char *fName)
{
    int iRet = 0;
    struct stat sobj;

    iRet = stat(fName, &sobj);
    if(iRet == -1)
    {
        perror("stat");
        return;
    }

    printf("\nFile MetaData Information: \n");
    printf("\n");

    printf("INODE number             :%ld \n", sobj.st_ino);
    printf("Number of Hardlinks      :%ld \n", sobj.st_nlink);
    printf("File Total size          :%ld \n", sobj.st_size);
    printf("File mode                :%o \n", sobj.st_mode);

    if(S_ISREG(sobj.st_mode))
    {
        printf("File Type                :Regular file\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("File Type                :Directory file \n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("File Type                :Character device\n");
    }
    else if(S_ISBLK(sobj.st_mode))
    {
        printf("File Type                :Block device\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("File Type                :Symbolic Link file\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("File Type                :Socket file\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("File Type                :Pipe file\n");
    }

    printf("User ID of owner         :%d \n", sobj.st_uid);
    printf("Group ID of owner        :%d \n", sobj.st_gid);

    printf("Last access Time         :%s \n", ctime(&sobj.st_atim.tv_sec));
    printf("Last modification Time   :%s \n", ctime(&sobj.st_mtim.tv_sec));
    printf("Last status Changed Time :%s \n", ctime(&sobj.st_ctim.tv_sec));

}

int main()
{
    char fName[100];
    
    printf("Enter Name of file : \n");
    scanf("%s", fName);

    Display(fName);

    return 0;
}