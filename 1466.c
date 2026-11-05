/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Felipe Silva Mantuani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 05/11/2026
Objetivo    : Implementar uma Árvore Binária e realizar seu percurso em largura
Dificuldade : Tive dificuldades em implementar o algoritmo de realizar o percurso em largura, para a impressão dos elementos
Uso de IA   : Utilizei para estudar o algoritmo de percurso em largura
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct NoArv{
    int valor;
    struct NoArv *esquerda, *direita;
} NoArv;


NoArv* pushArv(NoArv* raiz, int x){
    if(raiz==NULL){
        NoArv* aux = (NoArv*)malloc(sizeof(NoArv));
        aux->valor = x;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(x < raiz -> valor){
            raiz->esquerda = pushArv(raiz->esquerda, x);
        }
        else{
            raiz->direita = pushArv(raiz->direita, x);
        }
        return raiz;
    }
}

void BFS(NoArv* raiz, int n){
    if (raiz==NULL) return;
    NoArv** fila = (NoArv**)malloc(n*sizeof(NoArv*));
    if(fila == NULL) return;
    int inicio = 0, fim = 0;
    fila[fim++] = raiz;
    while(inicio<fim){
        NoArv* atual = fila[inicio++];
        if (inicio == 1) printf("%d", atual->valor);
        else printf(" %d", atual->valor);
        if(atual->esquerda != NULL){
            fila[fim++] = atual->esquerda;
        }
        if (atual-> direita != NULL){
            fila[fim++] = atual->direita;
        }
    }
    printf("\n");
    free(fila);
}

void limparArvore(NoArv* raiz){
    if(raiz == NULL) return;
    limparArvore(raiz->esquerda);
    limparArvore(raiz->direita);
    free(raiz);
}

int main(){
    int c, n;
    NoArv* raiz = NULL;
    scanf("%d", &c);
    for(int i = 1; i <= c; i++){
        scanf("%d", &n);
        for(int j = 0; j<n; j++){
            int x;
            scanf("%d", &x);
            raiz = pushArv(raiz, x);
        }
        
        printf("Case %d:\n", i);
        BFS(raiz, n);
        limparArvore(raiz);
        raiz = NULL;
        printf("\n");
    }

    return 0;
}