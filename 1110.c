/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 01/09/2026
Objetivo    : Implementar uma lista encadeada para simular o processo de descarte e movimentação de cartas, conforme descrito no problema.
Dificuldade : Intuitivamente eu tinha entendido como fazer a lista encadeada, porem na hora de implementar, tive dificuldades na lógica de apontar para o proximo
Uso de IA   : Usei IA para me auxiliar, principalmente na função de deletar.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

//Listas encadeadas
typedef struct No {
    int carta;
    struct No* proximo;
} No;

//Processamento de inserção na lista
No* push(No* base, int carta, int* tamanho) {
    No* novo = (No*)malloc(sizeof(No));
    novo->carta = carta;
    novo->proximo = NULL;
    base->proximo = novo;
    (*tamanho)++;
    return novo;
}

//Processamento de Deletar na lista
int pop(No* cabeca, int* tamanho) {
    No* removido = cabeca->proximo;
    int valor = removido->carta;
    
    cabeca->proximo = removido->proximo; 
    free(removido);
    (*tamanho)--; 
    
    return valor;
}

int main() {
    //Processamento de entrada
    int n;
    
    //Verificamos para n!=0
    while (scanf("%d", &n) && n != 0) {
        No* cabeca = (No*)malloc(sizeof(No));
        cabeca->proximo = NULL;
        No* base = cabeca;
        int tamanho = 0;
        
        //Processamento
        for(int i = 1; i <= n; i++){
            base = push(base, i, &tamanho);
        }
        
        printf("Discarded cards:");
        int primeiro_descarte = 1; //Sempre comeca com 1

        while(tamanho >= 2){
            int descartada = pop(cabeca, &tamanho);
            
            if(primeiro_descarte){
                printf(" %d", descartada);
                primeiro_descarte = 0;
            } else {
                printf(", %d", descartada);
            }
            
            int movida = pop(cabeca, &tamanho);
            if(tamanho == 0){
                base = cabeca;
            }
            base = push(base, movida, &tamanho);
        }
        
        printf("\n");
        if (tamanho == 1) {
            int ultima = pop(cabeca, &tamanho);
            printf("Remaining card: %d\n", ultima);
        }
        
        free(cabeca); 
    } 
    
    return 0;
}