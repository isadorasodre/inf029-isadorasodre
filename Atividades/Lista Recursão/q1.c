#include <stdio.h>
#include <stdlib.h>

int fatorial (int n);

int main ()
{
    int n = 5;
    int resultado = fatorial (n);
    printf("O fatorial de %d eh %d", n, resultado);
}

int fatorial (int n)
{
    if (n ==0)
    {
        return 1; 
    }
    else 
    {
        return  n * fatorial (n - 1);
    }
}