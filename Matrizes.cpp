#include <stdio.h>

// Função para ler a ordem da matriz
int leituraN() 
{
    int n;
    do 
    {
        printf("Digite a ordem da matriz (max %d): ", 40);
        scanf("%d", &n);
        if (n <= 0 || n > 40)
            printf("Valor inválido! Digite entre 1 e %d.\n", 40);
    } while (n <= 0 || n > 40);
    return n;
}

// Função para preencher uma matriz
void preencheMatriz(int n, float x[][40]) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int k = 0; k < n; k++) 
        {
            printf("posição [%d][%d]: ", i, k);
            scanf("%f", &x[i][k]);
        }
    }
}

// Função para imprimir matriz
void imprimeMatriz(int n, float x[][40]) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%.2f ", x[i][j]);
        }
        printf("\n");
    }
}

// Função para somar matrizes
void somaMatriz(float a[][40], float b[][40], float soma[][40], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int k = 0; k < n; k++) 
        {
            soma[i][k] = a[i][k] + b[i][k];
        }
    }
    printf("\nResultado da soma:\n");
        imprimeMatriz(n, soma);

}

// Função para multiplicar matrizes
void multiplicaMatriz(float a[][40], float b[][40], float mult[][40], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            mult[i][j] = 0;
            for (int k = 0; k < n; k++) 
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("\nResultado da multiplicação:\n");
        imprimeMatriz(n, mult);
}

// Programa principal com menu
int main() 
{
    int n, opcao;
    float A[40][40], B[40][40], C[40][40];

    n = leituraN();

    printf("\nPreenchendo a matriz A:\n");
    preencheMatriz(n, A);

    printf("\nPreenchendo a matriz B:\n");
    preencheMatriz(n, B);

    do 
    {
        printf("\nEscolha uma opção: \n");
        printf("1. Somar matrizes\n");
        printf("2. Multiplicar matrizes\n");
        printf("3. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) 
        {
            case 1:
                somaMatriz(A, B, C, n);
                break;
            case 2:
                multiplicaMatriz(A, B, C, n);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 3);
    return 0;
}