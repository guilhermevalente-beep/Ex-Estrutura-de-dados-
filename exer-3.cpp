#include <stdio.h>
#include <math.h>

typedef struct 
{
    int left;
    int right;
} REALTYPE;

//quebra o valor real em dois inteiros, um para a parte inteira e outro para a parte decimal 
 REALTYPE breakValue()
{
    REALTYPE valor;
    float x;
    
    printf("digite o valor real (separado por ponto): ");
    scanf("%f", &x);
    valor.left = (int)x;
    valor.right = (int)((x - valor.left)*100);
    printf("\nValor da esquerda: %d", valor.left);
    printf("\nValor da direita: %d\n\n", valor.right);
    return valor;
} 

//combina dois valores inteiros de uma estrutura, para que o da esquerda fique antes da vírgula e o da direita depois da vírgula 
float combValue (REALTYPE y)
{
    int digitos = 0;
    int aux = y.right;
    
    if(aux == 0)
        digitos = 1;
    else
        while(aux>0)
        {
            aux/=10;
            digitos++;
        }
        
    float k = (float) y.left + (float) y.right / pow(10, digitos);
    printf("\nValor real: %.2f", k);
    return k;    
}

//soma os valores reais de duas estruturas diferentes 
void soma(REALTYPE x, REALTYPE y)
{
    float k = combValue(x);
    float j = combValue(y);
    printf("\n A soma dos valores é: %.2f", k+j);
}

//subtrai o valor real da segunda estrutura do valor real da primeira estrutura 
void subtracao(REALTYPE x, REALTYPE y)
{
    float k = combValue(x);
    float j = combValue(y);
    printf("\n A subtração dos valores é: %.2f", k-j);
}

//multiplica os valores reais de duas estruturas 
void multiplicacao(REALTYPE x, REALTYPE y)
{
    float k = combValue(x);
    float j = combValue(y);
    printf("\n A multiplicação dos valores é: %.2f", k*j);
}

//divide o valor real da primeira estrutura pelo valor real da segunda estrutura 
void divisao(REALTYPE x, REALTYPE y)
{
    float k = combValue(x);
    float j = combValue(y);
    if (j==0.0)
        printf("\n Não é possivel efetuar a divisão.");
    else     
        printf("\n O quociente dos valores é: %.2f", k/j);
}

int main()
{
    int opcao;
    REALTYPE k = breakValue();
    REALTYPE j = breakValue();
    printf("Qual operação deve ser realizada?\n");
    printf("1. soma\n2.subtração\n3.multiplicação\n4.divisão\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            soma(k,j);
            break;
        case 2:
            subtracao(k,j);
            break;
        case 3:
            multiplicacao(k,j);
            break;
        case 4:    
            divisao(k,j);
            break;
        default:
            printf("Opção inválida.");
    }
return 0;    
}