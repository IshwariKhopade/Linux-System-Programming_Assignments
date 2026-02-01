///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Client.c
//  Description : Write program to create a shared library (.so) that contains 2 functions, Addition & Subtraction.
//  Author : Ishwari Bharat Khopade
//  Date : 01/02/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int, int);
    int iRet = 0;

    handle = dlopen("./Server1.so", RTLD_LAZY);          //RTLD_LAZY- used to bring library when needed

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }
    printf("Library gets loaded successfully\n");

    fp = (int(*)(int, int))dlsym(handle, "Addition");
    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(11,10);
    printf("Addition is: %d\n", iRet);

    fp = (int(*)(int, int))dlsym(handle, "Subtraction");
    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(11,10);
    printf("Subtraction is: %d\n", iRet);

    dlclose(handle);

    return 0;

}

