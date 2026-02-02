extern int Mod(int, int);

int Addition(int A, int B)
{
    int Ans = 0;
    Ans = A + B;
    return Ans;
}
int Subtraction(int A, int B)
{
    int Ans = 0;
    Ans = A - B;
    return Ans;
}
int Multiplication(int A, int B)
{
    int Ans = 0;
    Ans = A * B;
    return Ans;
}
int Division(int A, int B)
{
    int Ans = 0;
    Ans = A / B;
    return Ans;
}

int CallMod(int No1, int No2)
{
    // This will cause symbol resolution
    return Mod(No1, No2);
}


