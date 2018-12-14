#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

struct Arvore{
    int valor;
    Arvore * dir;
    Arvore * esq;
};

int recebervetor(int vetor[]);
void inserirArvore(Arvore *&tronco, int vetor[], int indice, int TAMAN);
void preOrdem(Arvore *& tronco);
void simetrica(Arvore *& tronco);
void posOrdem(Arvore *& tronco);


int main(void) {
    int vetor[TAM];
    int tamanho;
    int op = 0;
    Arvore * tronco = NULL;


    do{
        printf("\n1 - Inserir na Arvore\n2 - Imprimir Arvore\n\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                tamanho = recebervetor(vetor);
                inserirArvore(tronco, vetor, 0, tamanho);
                break;

            case 2:
                printf("Pre-ordem\n");
                preOrdem(tronco);
                printf("\n\nSimetrica\n");
                simetrica(tronco);
                printf("\n\nPos-ordem\n");
                posOrdem(tronco);
                break;

        }
    }while(op!=0);


    return 0;
}


int recebervetor(int vetor[]){

    char opcao = 's';
    int i =0;

    do{

        printf("Digite o elemento do vetor:\n");
        scanf("%d", &vetor[i]);
        i++;

        printf("Deseja inserir outro? (S/N)\n");
        scanf(" %c", &opcao);


    }while (opcao == 's' || opcao == 'S');

    return i;
}

void inserirArvore(Arvore *&tronco, int vetor[], int indice, int TAMAN){

    if (indice < TAMAN && vetor[indice] != 0) {
        tronco = (Arvore*) calloc(1,sizeof(tronco));

        tronco->valor = vetor[indice];
        tronco->esq = NULL;
        tronco->dir = NULL;

        inserirArvore(tronco->esq, vetor, 2 * indice + 1, TAMAN);
        inserirArvore(tronco->dir, vetor, 2 * indice + 2, TAMAN);
    }
}

void preOrdem(Arvore *& tronco){
    if(tronco != NULL){
        printf("%d\n", tronco->valor);
        preOrdem(tronco->esq);
        preOrdem(tronco->dir);
    }
}


void simetrica(Arvore *& tronco){

    if(tronco != NULL){
        simetrica(tronco->esq);
        printf("%d\n", tronco->valor);
        simetrica(tronco->dir);
    }
}


void posOrdem(Arvore *& tronco){

    if(tronco != NULL){

        posOrdem(tronco->esq);
        posOrdem(tronco->dir);
        printf("%d\n", tronco->valor);

    }
}