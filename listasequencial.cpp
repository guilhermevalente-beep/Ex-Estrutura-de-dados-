#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
typedef int Item;

typedef struct listaSequencial{
   Item itens[MAX];
   int tamanho;
}Lista;

// Cria uma nova lista
Lista* novaLista() 
{
   Lista* l = (Lista*)malloc(sizeof(Lista));
   if (l != NULL)
      l->tamanho = 0;
   return l;
}

// Verifica se a lista está cheia
bool verificaCheio(Lista* l) 
{
   return (l->tamanho >= MAX);
}

// Verifica se a lista está vazia
bool verificaVazio(Lista* l)
{
   return (l->tamanho == 0);
}

// Busca um item na lista
int buscar(Item x, Lista* l)
{                   
   for (int i = 0; i < l->tamanho; i++) 
   {
      if (l->itens[i] == x)
         return i;
   }
   return -1;
}

// Insere um item na lista (mantendo ordem crescente)
bool inserir(Item x, Lista* l)
{
   if (verificaCheio(l))
      return false;

   int i = l->tamanho - 1;
   while (i >= 0 && l->itens[i] > x) 
   {
      l->itens[i + 1] = l->itens[i]; //move os elementos maiores pra posição seguinte, até que estejam na ordem correta
      i--;
   }
   l->itens[i + 1] = x;
   l->tamanho++;
   return true;
}

// Remove um item da lista
bool remover(Item x, Lista* l)
{
   if (verificaVazio(l))
      return false;

   int pos = buscar(x, l);
   if (pos == -1)
      return false;

   for (int i = pos; i < l->tamanho - 1; i++)
   {
      l->itens[i] = l->itens[i + 1];
   }
   l->tamanho--;
   return true;
}

// Imprime todos os itens da lista
void imprimir(Lista* l) 
{
   if (verificaVazio(l)) 
   {
      printf("Lista vazia.\n");
      return;
   }
   
   for (int i = 0; i < l->tamanho; i++)
   {
      printf("%d ", l->itens[i]);
      printf("\n");
   }
      
}

// Libera a memória da lista
void liberarLista(Lista* l)
{
   free(l);
}

int main() 
{
   Lista* l = novaLista();
   Item x;
   int opcao;
   int pos;
   
   do
   {
      printf("Qual operação deseja realizar?\n");
      printf("1. Buscar item\n");
      printf("2. Inserir item\n");
      printf("3. Remover item\n");
      printf("4. Exibir lista\n");
      printf("5. Liberar lista e sair\n");
      printf("Opcao: ");
      scanf("%d", &opcao);

      switch (opcao) 
      {
         case 1:
            printf("\nDigite o valor a buscar: ");
            scanf("%d", &x);
            pos = buscar(x, l);
            if (pos != -1)
               printf("Item encontrado na posicao %d\n", pos);
             else
               printf("Item nao encontrado.\n");
            break;

         case 2:
            printf("Digite o valor a inserir: ");
               scanf("%d", &x);
               inserir(x, l);
               break;
                    

         case 3:
            printf("\nDigite o valor a remover: ");
            scanf("%d", &x);
            if (remover(x, l))
               printf("Item removido com sucesso!\n");
            else
               printf("Item nao encontrado.\n");
            break;

         case 4:
            printf("\nItens na lista: ");
            imprimir(l);
            break;

         case 5:
            liberarLista(l);
            printf("\nLista liberada.\n");
            break;

      default:
            printf("\nOpcao invalida.\n");
     }

   }while(opcao != 5);

   return 0;
}
