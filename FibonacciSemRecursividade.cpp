#include <stdio.h>

int main() 
{
    int n, i;
    int a = 0, b = 1, prox;

    printf("Quantos termos da sequencia de Fibonacci deseja mostrar? ");
    scanf("%d", &n);
    printf("Sequencia de %d números de Fibonacci:\n", n);

    for (i = 0; i < n; i++) 
    {
        printf("%d ", b);
        prox = a + b;  
        a = b;      
        b = prox;
    }
    printf("\n");
    return 0;
}