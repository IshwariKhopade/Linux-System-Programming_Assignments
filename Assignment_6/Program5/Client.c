///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Client.c
//  Description : Demonstrates difference between RTLD_LAZY and RTLD_NOW flags used with dlopen().
//                program loads same shared library twice. once using RTLD_LAZY and once using RTLD_NOW.
//  Author : Ishwari Bharat Khopade
//  Date : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle1 = NULL;
    void *handle2 = NULL;
    int (*fp)(int, int);
    int iRet = 0;
    int No1 = 0, No2 = 0;

    printf("Enter 2 Numbers: \n");
    scanf("%d%d", &No1, &No2);

    //---------------------RTLD_LAZY---------------------

    handle1 = dlopen("./Server.so", RTLD_LAZY);

    if(handle1 == NULL)
    {
        printf("Error loading the library with RTLD_LAZY: %s\n", dlerror());
        return -1;
    }
    printf("\nLibrary loaded successfully with RTLD_LAZY flag\n");

    // Addition
    fp = (int(*)(int, int))dlsym(handle1, "Addition");    
    iRet = fp(No1,No2);
    printf("Addition is: %d\n", iRet);

    // Calling unresolved symbol
    fp = (int(*)(int, int))dlsym(handle1, "CallMod");    
    printf("Calling unresolved symbol using RTLD_LAZY\n");
    
    // This will cause runtime error
    iRet = fp(No1, No2);
    printf("Mod is: %d\n", iRet);

    dlclose(handle1);

    //---------------------RTLD_NOW---------------------

    handle2 = dlopen("./Server.so", RTLD_NOW);

    if(handle2 == NULL)
    {
        printf("\nLibrary failed to load with RTLD_NOW: %s\n", dlerror());
    }
    else
    {
        printf("\nLibrary loaded successfully with RTLD_NOW flag\n");

        // Addition
        fp = (int(*)(int, int))dlsym(handle2, "Addition");    
        iRet = fp(No1,No2);
        printf("Addition is: %d\n", iRet);

        dlclose(handle2);
    }

    return 0;
}

