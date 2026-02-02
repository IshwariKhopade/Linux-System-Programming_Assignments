///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Client.c
//  Description : Program to Demonstrate dynamic library search path resolution.
//  Author : Ishwari Bharat Khopade
//  Date : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void hello();

int main()
{
    printf("Client Program\n");

    hello();

    return 0;
}


//gcc Client.c -L./serverlib -lserver -o Client
//./Client

/*

1) On execution without LD_LIBRARY_PATH we will get below output:

./Client: error while loading shared libraries: libserver.so: cannot open shared object file: No such file or directory

Reason: It searches shared library in /lib, /usr/lib, etc
        It does not search in custom Directory & so runtime linker Fails

2)On execution with LD_LIBRARY_PATH we will get below output: 

Client Program
Shared Library

Reason: LD_LIBRARY_PATH tells loader where to search, loader finds libmylib.so in Custom Directory & Program is executed.

*/
