#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct No {
   Item info;
   struct No *prox;
} No;

//inicia a lista 
No* criarLista()
{
   No *cab = (No*) malloc(sizeof(No));
   if (cab == NULL) {
      printf("Erro ao alocar memória para a lista.\n");
      exit(1);
   }
   cab->prox = NULL;
   return cab;
}

//busca um item na lista
No* buscarOrdenado(No *cab, Item x) 
{
   No *ant = cab;
   No *pt = cab->prox;
   while (pt != NULL && pt->info < x) 
   {
      ant = pt;
      pt = pt->prox;
   }
   return ant;
}

//insere um item na lista
void inserirOrdenado(No *cab, Item x) 
{
   No *ant = buscarOrdenado(cab, x);
   if (ant->prox != NULL && ant->prox->info == x) 
   {
      printf("O item já está na lista.\n");
      return;
   }
   No *novo = (No*) malloc(sizeof(No));
   if (novo == NULL) 
   {
      printf("Erro ao alocar memória para novo item.\n");
      return;
   }
   novo->info = x;
   novo->prox = ant->prox;
   ant->prox = novo;
   printf("Item inserido com sucesso.\n");
}

//remove um item da lista
void removerOrdenado(No *cab, Item x) 
{
   No *ant = buscarOrdenado(cab, x);
   if (ant->prox == NULL || ant->prox->info != x) 
   {
      printf("O item não está na lista.\n");
      return;
   }
   No *remover = ant->prox;
   ant->prox = remover->prox;
   free(remover);
   printf("Item removido com sucesso.\n");
}

//imprime os itens da lista 
void imprimirLista(No *cab) 
{
   No *pt = cab->prox;
   if (pt == NULL) {
      printf("Lista vazia.\n");
      return;
   }
   printf("Lista: ");
   while (pt != NULL) 
   {
      printf("%d -> ", pt->info);
      pt = pt->prox;
   }
   printf("NULL\n");
}

//remove todos os itens da lista 
void limparLista(No *cab) 
{
   No *pt = cab->prox;
   while (pt != NULL) 
   {
      No *temp = pt;
      pt = pt->prox;
      free(temp);
   }
   cab->prox = NULL;
   printf("Lista limpa com sucesso.\n");
}

//programa principal
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

      switch(opcao) 
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

   } while(opcao != 0);
   return 0;
}

