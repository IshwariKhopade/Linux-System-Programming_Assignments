///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Client.c
//  Description : Write program to Demonstrate what happens when, valid .so is load & Invalid function name is passed to dlsym().
//  Author : Ishwari Bharat Khopade
//  Date : 02/02/2026
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
    int No1 = 0, No2 = 0;

    //dlopen loads shared library at runtime
    handle = dlopen("./Server.so", RTLD_LAZY);          //RTLD_LAZY- used to bring library when needed

    if(handle == NULL)
    {
        printf("Error loading the library: %s\n", dlerror());
        return -1;
    }
    printf("Library gets loaded successfully\n");

    printf("Enter 2 Numbers: \n");
    scanf("%d%d", &No1, &No2);

    //fetching valid function Addition
    fp = (int(*)(int, int))dlsym(handle, "Addition");    
    if(fp == NULL)
    {
        printf("Error getting address of function: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(No1,No2);
    printf("Addition is: %d\n", iRet);
        
    //fetching valid function Subtraction
    fp = (int(*)(int, int))dlsym(handle, "Subtraction");    
    if(fp == NULL)
    {
        printf("Error getting address of function: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(No1,No2);
    printf("Subtraction is: %d\n", iRet);

    //fetching valid function Multiplication
    fp = (int(*)(int, int))dlsym(handle, "Multiplication");    
    if(fp == NULL)
    {
        printf("Error getting address of function: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(No1,No2);
    printf("Multiplication is: %d\n", iRet);

    //fetching valid function Division
    fp = (int(*)(int, int))dlsym(handle, "Division");    
    if(fp == NULL)
    {
        printf("Error getting address of function: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(No1,No2);
    printf("Division is: %d\n", iRet);

    //fetching Invalid function MOD
    fp = (int(*)(int, int))dlsym(handle, "Mod");    
    if(fp == NULL)
    {
        printf("Error getting address of function: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(No1,No2);
    printf("Mod is: %d\n", iRet);

    dlclose(handle);

    return 0;

}

