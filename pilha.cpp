#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define MAX 100
typedef int Item;

typedef struct pilha{
   int topo;
   Item itens[MAX];
}Pilha;

bool estaCheio(Pilha *p)
{
   if (p->topo == MAX)
      return true;
   return false; 
}

bool empilhar(Item x, Pilha *p)
{
   if (estaCheio(p))
   {
      printf("A pilha esta cheia.\n");
      return false;
   }
   p->itens[p->topo] = x;
   p->topo++;
   return true;
}

bool estaVazio(Pilha *p)
{
   if (p->topo == 0)
      return true;
   return false;
}

Item desempilhar(Item x, Pilha *p)
{
   if (estaVazio(p))
   {
      printf("A pilha esta vazia.\n");
      return -1;
   }
   p->topo--;
   x = p->itens[p->topo];
   return x;  
}

void imprimePilha(Pilha *p)
{
   if (estaVazio(p))
   {
      printf("A pilha esta vazia.\n");
      return;
   }
   printf("Pilha do topo ate a base: ");
   for (int i = p->topo - 1; i >= 0; i--)
   {
      printf("%d ", p->itens[i]);    
   }
   printf("\n");
}

int main()
{
   Pilha p;
   p.topo = 0;
   int opcao;
   Item x;
   
   do
   {
      printf("Qual operacao deseja realizar?\n1. Empilhar\n2. Desempilhar\n3. Imprimir pilha\n4. Sair\n");
      scanf("%d", &opcao);

      switch(opcao)
      {
      case 1:
         printf("Digite um valor: ");
         scanf("%d", &x);
         empilhar(x, &p);
         break;
      case 2:
         x = desempilhar(x, &p);
         if (x != -1)
            printf("Valor desempilhado: %d\n", x);
         break;
      case 3:
         imprimePilha(&p);
         break;   
      case 4:
         break;
       default:
         printf("Opcao invalida.\n");
     
      }
   }while(opcao != 4);
   return 0;
}
