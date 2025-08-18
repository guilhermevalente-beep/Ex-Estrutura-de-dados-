#include <stdio.h>

void hanoi(int n, char origem, char trabalho, char destino) {
    if (n > 0) {
        // move n-1 discos da origem para a torre auxiliar
        hanoi(n - 1, origem, destino, trabalho);

        // move o disco maior para o destino
        printf("Mover disco %d de %c para %c\n", n, origem, destino);

        // move os n-1 discos da torre auxiliar para o destino
        hanoi(n - 1, trabalho, origem, destino);
    }
}

int main() {
    int n;
    
    printf("com quantos discos deve ser feita a torre de hanoi?");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}