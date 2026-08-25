/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 25/08/2026
Objetivo    : Ler um vetor dinamicamente de numeros inteiros e positivos fornecido pelo usuário, e mostrar qual é o maior elemento e a posição do mesmo.
Dificuldade : Fácil
Uso de IA   : Não fiz nenhum uso de IA para implementar esse código.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(){
    //Processamento de entrada
    unsigned int *vetor, maior;
    int pos;
    vetor = malloc(100*sizeof(unsigned int));
    for (int i = 0; i < 100; i++){
        scanf("%u", vetor+i);
    }
    pos = 0;
    maior = *(vetor);

    //processamento
    for(int i = 0; i<100; i++){
        if(maior < *(vetor+i)){
            maior = *(vetor + i);
            pos = i;
        }
    }

    //Processamento das saidas
    printf("%u\n", maior);
    printf("%d\n", pos + 1);
    free(vetor);
}