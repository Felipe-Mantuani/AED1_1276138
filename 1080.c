/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 21/08/2026
Objetivo    : Ler um vetor de numeros inteiros e positivos fornecido pelo usuário, e mostrar qual é o maior elemento e a posição do mesmo.
Dificuldade : Fácil
Uso de IA   : Não fiz nenhum uso de IA para implementar esse código.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main(){
    //declaracao de variaveis
    unsigned int vet[100];
    unsigned int maior;
    int pos;

    //processamento das entradas
    for(int i = 0; i < 100; i++){
        scanf("%u", &vet[i]);
    }

    maior = vet[0];
    pos = 0;
    
    //Processamento
    for(int i = 0; i < 100; i++){
        if(maior < vet[i]){
            maior = vet[i];
            pos = i;
        }
    }

    //Processamento das saidas
    printf("%u\n", maior);
    printf("%d\n", pos + 1);

    return 0;
}