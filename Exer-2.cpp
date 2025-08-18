#include <stdio.h>

int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1; 
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n, i;

    printf("Quantos termos da sequencia de Fibonacci deseja mostrar? ");
    scanf("%d", &n);

    printf("Sequencia de %d números de Fibonacci:\n", n);
    for (i=1;i<=n;i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}