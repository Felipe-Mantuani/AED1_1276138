/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 26/10/2026
Objetivo    : Sequencia
Dificuldade : Fácil
Uso de IA   : Não
-------------------------------------------------------------------------- */
#include <stdio.h>

int main(){
    int i = 1;
    for (int j = 60; j>= 0; j -= 5){
        printf("I=%d J=%d\n", i, j);
        i+=3;
    }
}