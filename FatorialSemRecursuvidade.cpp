#include <stdio.h>

// Função para calcular o fatorial
int fatorial(int n) {
    int fat= 1;
    if (n < 0) {
        return -1; 
    }
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int main()
{
    int n;

    printf("digite o número no qual deve ser calculado o fatorial: ");
    scanf("%d", &n);

    int fat = fatorial(n);

    if(fat == -1)
        printf("Fatorial nao definido para numeros negativos.\n");
    else
        printf("%d! = %d\n", n, fat);
    return 0;
}