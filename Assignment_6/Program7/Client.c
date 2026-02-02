///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File Name : Client.c
//  Description : Create Shared Library that Maintains Global Variable inside library, write modify, display & reset functions.
//                Write dynamically linked client prog to demonstrate persistence of gloabal variable acros  multiple function calls. 
//  Author : Ishwari Bharat Khopade
//  Date : 02/02/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void modify(int value);
void display();
void reset();

int main()
{
    printf("Initial Value: \n");
    display();

    printf("Modifying Value by 5: \n");
    modify(5);
    display();

    printf("Reseting Value\n");
    reset();
    display();

    return 0;
}


/*

gcc -fPIC -c Server.c 
gcc -shared -o libserver.so Server.o 
gcc Client.c -L. -lserver -o Client
export LD_LIBRARY_PATH=.
./Client


*/
