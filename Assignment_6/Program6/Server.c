#include <stdio.h>

void hello()
{
    printf("Shared Library\n");
}



//gcc -fPIC -c Server.c 
//gcc -shared -o libserver.so Server.o 


//for custom dir
//mkdir mylibdir
//mv libserver.so serverlib/
