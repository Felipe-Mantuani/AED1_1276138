/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 01/09/2026
Objetivo    : verificar se os parenteses fecha, usando estrutura de pilhas
Dificuldade : O que tive mais dificuldade foi pensar na logica de deletar a pilha
Uso de IA   : fiz o uso de IA para me auxiliar para deletar
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

//Criacao do No
typedef struct No{
    char c;
    struct No *prox;
} No;

No* criarPilha(){
    No *cabeca = (No*)(malloc(sizeof(No)));
    cabeca->prox = NULL;
    return cabeca;
}

No* push (No *cabeca, char caractere){
    No *novo = (No*)malloc(sizeof(No));
    novo->c = caractere;  
    novo->prox = cabeca->prox;
    cabeca->prox = novo; 
}

int pop(No* cabeca){
    if(cabeca->prox==NULL){
        return 0; //pilha vazia
    }
    No *aux = cabeca->prox;
    cabeca->prox = aux->prox;
    free(aux);
    return 1;
}

void esvaziarPilha(No* cabeca){
    while(cabeca->prox != NULL){
        pop(cabeca);
    }
}

int main(){
    //processamento de entrada
    char expressao[1002];
    No *pilha = criarPilha();

    //processamento
    while(fgets(expressao, sizeof(expressao), stdin) != NULL){
      int invalido = 0;
      for(int i = 0; expressao[i]!='\0' && expressao[i]!= '\n'; i++){
        if(expressao[i] == '('){
            push(pilha, '(');
        }
        else if(expressao[i] == ')'){
            if(!pop(pilha)){
                invalido = 1;
                break;
            }
        }
      } 
      //processamento de saida
        if(invalido || pilha->prox != NULL){
            printf("incorrect\n");
        } else {
            printf("correct\n");
        }
        esvaziarPilha(pilha);
    }
    free(pilha);

    return 0;
}