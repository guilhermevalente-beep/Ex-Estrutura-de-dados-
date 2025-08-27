#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define MAX 100
typedef int Item;

typedef struct fila{
   int inicio;
   int fim;
   Item itens[MAX];
}Fila;

bool estaCheio(Fila *f)
{
   if ((f->fim + 1) % MAX == f->inicio)
      return true;
   return false; 
}

bool estaVazio(Fila *f)
{
   if (f->inicio == f->fim)
      return true;
   return false;
}

bool enfileirar(Item x, Fila *f)
{
   if (estaCheio(f))
   {
      printf("A fila esta cheia.\n");
      return false;
   }
   f->itens[f->fim] = x;
   f->fim = (f->fim + 1) % MAX;
   return true;
}

Item desenfileirar(Fila *f)
{
   if (estaVazio(f))
   {
      printf("A fila esta vazia.\n");
      return -1;
   }
   Item x = f->itens[f->inicio];
   f->inicio = (f->inicio + 1) % MAX;
   return x;  
}

void imprimeFila(Fila *f)
{
   if (estaVazio(f))
   {
      printf("A fila esta vazia.\n");
      return;
   }
   printf("Fila do inicio ate o fim: ");
   int i = f->inicio;
   while (i != f->fim)
   {
      printf("%d ", f->itens[i]);
      i = (i + 1) % MAX;
   }
   printf("\n");
}

int main()
{
   Fila f;
   f.inicio = 0;
   f.fim = 0;
   int opcao;
   Item x;
   
   do
   {
      printf("\nQual operacao deseja realizar?\n");
      printf("1. Enfileirar\n");
      printf("2. Desenfileirar\n");
      printf("3. Imprimir fila\n");
      printf("4. Sair\n");
      printf("Opcao: ");
      scanf("%d", &opcao);

      switch(opcao)
      {
         case 1:
            printf("Digite um valor: ");
            scanf("%d", &x);
            enfileirar(x, &f);
            break;
         case 2:
            x = desenfileirar(&f);
            if (x != -1)
               printf("Valor desenfileirado: %d\n", x);
            break;
         case 3:
            imprimeFila(&f);
            break;   
         case 4:
            printf("Saindo...\n");
            break;
         default:
            printf("Opcao invalida.\n");
      }
   }while(opcao != 4);
   
   return 0;
}
