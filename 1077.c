/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 25/09/2026
Objetivo    : Transformar uma infixa para posfixa
Dificuldade : Tive dificuldades na precedencia dos simbolos, e tratar eles para a saida
Uso de IA   : utilizei IA para me auxiliar na minha dificuldade, porem pedi apenas para me dar dicas, sem dar o codigo
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    struct No* prox;
    char operador;
} No;

void push(No* topo, char op) {
    No* novo = (No*)malloc(sizeof(No));
    novo->operador = op;
    novo->prox = topo->prox;
    topo->prox = novo;
}

char pop(No* topo) {
    No* aux;
    char removido;
    if (topo->prox != NULL) {
        aux = topo->prox;
        topo->prox = aux->prox;
        removido = aux->operador;
        free(aux);
        return removido;
    }
    return -1;
}

//verificacao do operador que esta no topo
char verificar(No* topo) {
    if (topo->prox != NULL) {
        return topo->prox->operador;
    }
    return '\0';
}

int ehOperando(char c) {
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;
}

int prioridade(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void limparPilha(No* topo) {
    while (topo->prox != NULL) {
        pop(topo);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    for (int i = 1; i <= n; i++) {
        No* topo = (No*)malloc(sizeof(No));
        topo->prox = NULL;
        
        char entrada[302];
        char saida[302];
        int tamanhoSaida = 0;

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            free(topo);
            break;
        }
        //Para eliminar o \n do fgets
        entrada[strcspn(entrada, "\n")] = '\0';
        int len = strlen(entrada);
        for (int j = 0; j < len; j++) {
            char atual = entrada[j];

            //operando vai para o vetor de saida
            if (ehOperando(atual)) {
                saida[tamanhoSaida++] = atual;
            } 
            else if (atual == '(') {
                push(topo, atual);
            } 
            else if (atual == ')') {
                while (verificar(topo) != '(' && verificar(topo) != '\0') {
                    saida[tamanhoSaida++] = pop(topo);
                }
                pop(topo);
            } 
            else if (atual == '+' || atual == '-' || atual == '*' || atual == '/' || atual == '^') {
                while (verificar(topo) != '\0' && verificar(topo) != '(' && prioridade(verificar(topo)) >= prioridade(atual)) {
                    saida[tamanhoSaida++] = pop(topo);
                }
                push(topo, atual);
            }
        }

        while (verificar(topo) != '\0') {
            saida[tamanhoSaida++] = pop(topo);
        }
        
        //Apresentar a saida
        saida[tamanhoSaida] = '\0';
        printf("%s\n", saida);

        limparPilha(topo);
        free(topo);
    }
    return 0;
}