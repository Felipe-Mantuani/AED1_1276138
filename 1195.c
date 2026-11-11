/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 10/11/2026 
Objetivo    : construir uma árvore binária de busca a partir dos números fornecidos e imprimir seus valores utilizando os três percursos clássicos: pré-ordem (prefixo), em-ordem (infixo) e pós-ordem (posfixo).
Dificuldade : Média
Uso de IA   : Não utilizei IA
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

No* push(No* raiz, int x) {
    if (raiz == NULL) {
        No* aux = (No*)malloc(sizeof(No));
        aux->valor = x;
        aux->direita = NULL;
        aux->esquerda = NULL;
        return aux;
    } else {
        if (x < raiz->valor) {
            raiz->esquerda = push(raiz->esquerda, x);
        } else {
            raiz->direita = push(raiz->direita, x);
        }
        return raiz;
    }
}

int primeiro;

void inf(No* raiz) {
    if (raiz != NULL) {
        inf(raiz->esquerda);
        if (primeiro) {
            printf("%d", raiz->valor);
            primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
        inf(raiz->direita);
    }
}

void pre(No* raiz) {
    if (raiz != NULL) {
        if (primeiro) {
            printf("%d", raiz->valor);
            primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
        pre(raiz->esquerda);
        pre(raiz->direita);
    }
}

void post(No* raiz) {
    if (raiz != NULL) {
        post(raiz->esquerda);
        post(raiz->direita);
        if (primeiro) {
            printf("%d", raiz->valor);
            primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
    }
}

void limparArvore(No* raiz) {
    if (raiz == NULL) return;
    limparArvore(raiz->esquerda);
    limparArvore(raiz->direita);
    free(raiz);
}

int main() {
    No *raiz = NULL;
    int n;
    
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 1; i <= n; i++) {
        int a;
        if (scanf("%d", &a) != 1) break;
        
        for (int j = 0; j < a; j++) {
            int x;
            if (scanf("%d", &x) != 1) break;
            raiz = push(raiz, x);
        }
        
        printf("Case %d:\n", i);
        
        primeiro = 1;
        printf("Pre.: ");
        pre(raiz);
        printf("\n");
        
        primeiro = 1;
        printf("In..: ");
        inf(raiz);
        printf("\n");
        
        primeiro = 1;
        printf("Post: ");
        post(raiz);
        printf("\n\n");
        
        limparArvore(raiz);
        raiz = NULL;
    }
    
    return 0;
}