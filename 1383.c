/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 21/08/2026
Objetivo    : Ler um vetor de numeros inteiros e positivos fornecido pelo usuário, e mostrar qual é o maior elemento e a posição do mesmo.
Dificuldade : A logica da verificacao por blocos de 3x3
Uso de IA   : Usei IA para me auxiliar na logica da verificacao por blocos
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    //declaracao de variaveis
    int n, sudoku[9][9], numeros[10], valido;

    //processamento de entrada
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        // Leitura do Sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        valido = 1;

        // Verifica as linhas
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                numeros[j] = 0;
            }
            for (int j = 0; j < 9; j++) {
                if (numeros[sudoku[i][j]] == 1) {
                    valido = 0;
                }
                numeros[sudoku[i][j]] = 1;
            }
        }

        // Verifica as colunas
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 10; i++) {
                numeros[i] = 0;
            }
            for (int i = 0; i < 9; i++) {
                if (numeros[sudoku[i][j]] == 1) {
                    valido = 0;
                }
                numeros[sudoku[i][j]] = 1;
            }
        }

        // Verifica os blocos 3x3
        for (int linha = 0; linha < 9; linha += 3) {
            for (int coluna = 0; coluna < 9; coluna += 3) {

                for (int i = 0; i < 10; i++) {
                    numeros[i] = 0;
                }
                for (int i = linha; i < linha + 3; i++) {
                    for (int j = coluna; j < coluna + 3; j++) {
                        if (numeros[sudoku[i][j]] == 1) {
                            valido = 0;
                        }
                        numeros[sudoku[i][j]] = 1;
                    }
                }
            }
        }

        //Processamento de saida
        printf("Instancia %d\n", instancia);
        if (valido == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}