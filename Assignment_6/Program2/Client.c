///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Client.c
//  Description : Write program to demonstrate runtime dynamic linking, use dlopen(), dlsym(), dlerror(), dlclose().
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
    char *error = NULL;
    int iRet = 0;

    //dlopen() loads shared library at runtime
    handle = dlopen("./Server.so", RTLD_LAZY);          //RTLD_LAZY- used to bring library when needed

    if(handle == NULL)
    {
        printf("Error loading the library: %s\n", dlerror());
        return -1;
    }
    printf("Library gets loaded successfully\n");

    fp = (int(*)(int, int))dlsym(handle, "Addition");    //dlsym() fetches address of function
    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(111,100);
    printf("Addition is: %d\n", iRet);

    fp = (int(*)(int, int))dlsym(handle, "Subtraction");
    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(111,100);
    printf("Subtraction is: %d\n", iRet);

    dlclose(handle);

    return 0;

}
