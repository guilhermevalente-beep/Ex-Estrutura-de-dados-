#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct No
{
   Item info;
   struct No *prox;
   struct No *ant;
} No;

No* criarLista()
{
   No *cab = (No*) malloc(sizeof(No));
   if (cab == NULL)
   {
      printf("Erro ao criar a lista.\n");
      exit(1);
   }

   // Lista circular: cabeça aponta pra ela mesma
   cab->prox = cab;
   cab->ant = cab;

   return cab;
}

No* buscarOrdenado(No *cab, Item x)
{
   No *pt = cab->prox;
   No *ant = cab;

   while (pt != cab && pt->info < x)
   {
      ant = pt;
      pt = pt->prox;
   }

   return ant;
}

void inserirOrdenado(No *cab, Item x)
{
   No *ant = buscarOrdenado(cab, x);

   if (ant->prox != cab && ant->prox->info == x)
   {
      printf("O item já está na lista.\n");
      return;
   }

   No *novo = (No*) malloc(sizeof(No));
   if (novo == NULL)
   {
      printf("Erro ao alocar memória.\n");
      return;
   }

   novo->info = x;
   novo->prox = ant->prox;
   novo->ant = ant;

   ant->prox->ant = novo;
   ant->prox = novo;

   printf("Item inserido com sucesso.\n");
}

void removerOrdenado(No *cab, Item x)
{
   No *ant = buscarOrdenado(cab, x);

   if (ant->prox == cab || ant->prox->info != x)
   {
      printf("O item não está na lista.\n");
      return;
   }

   No *remover = ant->prox;
   ant->prox = remover->prox;
   remover->prox->ant = ant;

   free(remover);

   printf("Item removido com sucesso.\n");
}

void imprimirLista(No *cab)
{
   No *pt = cab->prox;
   if (pt == cab)
   {
      printf("Lista vazia.\n");
      return;
   }

   printf("Lista: ");
   while (pt != cab)
   {
      printf("%d ", pt->info);
      pt = pt->prox;
   }
}

void limparLista(No *cab)
{
   No *pt = cab->prox;
   while (pt != cab)
   {
      No *temp = pt;
      pt = pt->prox;
      free(temp);
   }

   cab->prox = cab;
   cab->ant = cab;

   printf("Lista limpa com sucesso.\n");
}

int main()
{
   No *lista = criarLista();
   int opcao, valor;

   do
   {
      printf("\nMenu:\n");
      printf("1 - Inserir item\n");
      printf("2 - Remover item\n");
      printf("3 - Imprimir lista\n");
      printf("4 - Limpar lista\n");
      printf("0 - Sair\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao)
      {
         case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserirOrdenado(lista, valor);
            break;
         
         case 2:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            removerOrdenado(lista, valor);
            break;

         case 3:
            imprimirLista(lista);
            break;

         case 4:
            limparLista(lista);
            break;

         case 0:
            limparLista(lista);
            free(lista);
            printf("Programa encerrado.\n");
            break;

         default:
            printf("Opcao invalida. Tente novamente.\n");
      }

   } while (opcao != 0);
   return 0;
}

