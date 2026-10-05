/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 04/10/2026
Objetivo    : Simular a reorganização dos vagões utilizando uma pilha.
Dificuldade : Tive dificuldades em entender como que funcionava a organização dos vagões para a saída
Uso de IA   : Fiz uso de IA para me ajudar a entender o enunciado
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
} No;

void push(No* topo, int x){
    No* novo = (No*)malloc(sizeof(No));
    novo -> valor = x;
    novo->prox = topo->prox;
    topo->prox = novo;
}

int pop(No* topo){
    if(topo->prox != NULL){
        No* aux;
        aux = topo->prox;
        topo->prox = aux->prox;
        int removido = aux->valor;
        free(aux);
        return removido;
    }
    return -1;
}

int verTopo(No* topo){
    if(topo->prox != NULL){
        return topo->prox->valor;
    }
    return -1;
}

void limparPilha(No* topo){
    while(topo->prox != NULL){
        pop(topo);
    }
}

int main(){
    int v;
    while(1){
        scanf("%d", &v);
        if(v == 0) break;
        while(1){
            int primeiro;
            scanf("%d", &primeiro);
            if(primeiro == 0) break;
            int ordem[v];
            ordem[0] = primeiro;
            for(int i = 1; i < v; i++){
                scanf("%d", &ordem[i]);
            }
            No *topo = (No*)malloc(sizeof(No));
            topo -> prox = NULL;
            int proximoVagao = 1, verificar = 1;
            for(int i = 0; i < v; i++){
                int desejado = ordem[i];
                while(proximoVagao <= v && verTopo(topo) != desejado){
                    push(topo, proximoVagao);
                    proximoVagao++;
                }
                if(verTopo(topo) == desejado){
                    pop(topo);
                }
                else{
                    verificar = 0;
                    break;
                }
            }
            if(verificar) printf("Yes\n");
            else printf("No\n");
            limparPilha(topo);
            free(topo);
        }
        printf("\n");
    }
    return 0;
}