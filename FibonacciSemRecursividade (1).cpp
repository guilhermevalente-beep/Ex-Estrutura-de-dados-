

#include <stdio.h>
//função para calcular a sequência de Fibonacci
void fibonacci(int n) 
{
    int a = 0, b = 1, c;

    if (n >= 1) printf("%d ", a);
    if (n >= 2) printf("%d ", b);

    for (int i = 3; i <= n; i++) 
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}
int main()
{
    int n;
    
    printf("Digite quantos números da sequência de Fibonacci devem ser calculados: ");
    scanf("%d", &n);
    
    fibonacci(n);
    return 0;
}
