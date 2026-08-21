/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1180
Data        : 21/08/2026
Objetivo    : Ler um vetor fornecido pelo usuário, e mostrar qual é o menor elemento e a posição do mesmo.
Dificuldade : Fácil
Uso de IA   : Não fiz nenhum uso de IA para implementar esse código.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main(){
    //Inicializacao das variaveis
    int N, menor, pos;

    //Fazendo que o usuario digite o tamanho do vetor no tamanho certo
    do {
        scanf("%d", &N);
    } while(N < 1 || N > 1000);

    //inicializa vetor
    int vet[N];

    //Leitura dos elementos
    for (int i = 0; i<N; i++){
        scanf(" %d", &vet[i]);
    }

    menor = vet[0];     //menor comeca no primeiro elemento
    pos = 0;    //posicao comeca em 0

    //processamento
    for(int i = 0; i<N; i++){
        //se variavel menor > vet[i] entao vet[i] e o novo menor
        if(menor > vet[i]){
            menor = vet[i];
            pos = i;
        }
    }

    //processamento das saidas
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);
    return 0;
}