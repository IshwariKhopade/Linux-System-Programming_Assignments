#include <stdio.h>

int count = 0;

void modify(int value)
{
    count += value;
}

void display()
{
    printf("Count value: %d\n", count);
}

void reset()
{
    count = 0;
}
