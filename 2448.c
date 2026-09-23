/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 23/09/2026
Descricao   : Verificar o tempo necessário que o carteiro vai percorrer para fazer as entregas
Objetivo    : Verificar o tempo que vai gastar percorrendo o vetor, utilizando busca binaria
Dificuldade : Media
Uso de IA   : Nao
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int casas[], int N, int valor){
    int inicio = 0;
    int fim = N - 1;
    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (casas[meio] == valor) {
            return meio;
        }
        if(casas[meio]<valor){
            inicio = meio+1;
        }
        else{
            fim = meio-1;
        }
    }
    return -1;
}

int main(){
    int N, M;
    do{
        scanf("%d %d", &N, &M);
    } while((N<1 || N>45000) || (M<1 || M>45000));
    int casas[N], ordem[M];
    for(int i = 0; i<N; i++){
        scanf("%d", &casas[i]);
    }
    for(int j = 0; j<M; j++){
        scanf("%d", &ordem[j]);
    }

    long long tempo = 0;
    int posAtual = 0;

    for(int k = 0; k<M; k++){
        int posDestino = buscaBinaria(casas, N, ordem[k]);
        tempo += abs(posDestino - posAtual);
        posAtual = posDestino;
    }

    printf("%lld\n", tempo);

    return 0;
}