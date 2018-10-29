//pinto

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

struct Aluno {
    int mat;
    char nome[80];
    float nota;
    char sexo;
    Aluno * proximo;
};
//-----------------------------------
void menu(int &option, Aluno*&first);
void adicionar_comeco(Aluno*&first);
void get_data(Aluno *&new_node, Aluno*&first);
void release_last(Aluno *&first);
void exibir(Aluno*&first);
//-----------------------------------
int main() {
    Aluno * first = nullptr;
    int option;

    do {
        menu(option, first);
    }while(option != 0);
}

void menu(int &option, Aluno*&first) {
    system("clear");

    printf("Digite a opção desejada:\n1)Adicionar\n2)Remover no fim\n3)Exibir\n\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            adicionar_comeco(first);
            break;
        case 2:
            release_last(first);
            break;
        case 3:
            exibir(first);
            break;
        case 0:
            break;

        default:
            printf("Opção não existente.\n");
            sleep(2);
    }
}

void adicionar_comeco(Aluno*&first) {
    Aluno * new_node;

    system("clear");

    new_node = (Aluno*) calloc (1,sizeof(Aluno));

    get_data(new_node, first);


    if(new_node == nullptr) {
        printf("Failed to allocate new node.\n");
        sleep(3);
    }else{
        if(first == nullptr) {
            first = new_node;
            first->proximo = nullptr;
        }else{
            Aluno * auxiliary;
            auxiliary = first;
            first = new_node;
            first->proximo = auxiliary;
        }
    }
}


void get_data(Aluno *&new_node, Aluno*&first) {
    if(first != nullptr) {
        new_node->mat = first->mat + 1;
    }else{
        new_node->mat = 1;
    }
    system("clear");

    printf("Digite o primeiro nome do aluno: ");
    scanf("%s", new_node->nome);

    printf("Digite a nota do aluno: ");
    scanf("%f", &new_node->nota);

    printf("Digite o sexo do aluno (M-F): ");
    scanf(" %c", &new_node->sexo);

    system("clear");
}

void release_last(Aluno *&first) {
    Aluno * atual, *before;
    atual = first;

    while(atual->proximo != nullptr) {
        before = atual;
        atual = atual->proximo;
    }
    if(first->proximo != nullptr) {
        before->proximo = nullptr;
    }
    free(atual);
}

void exibir(Aluno*&first) {
    Aluno * atual = first;
    system("clear");
    while(atual != nullptr) {
        printf("\n--------------------------\n");
        printf("Código: %d\n", atual->mat);
        printf("Nome: %s\n", atual->nome);
        printf("Nota: %.1f\n", atual->nota);
        printf("Sexo: %c\n", atual->sexo);
        if(atual->proximo == nullptr) {
            printf("\n--------------------------\n");
        }
        sleep(5);
        atual = atual->proximo;
    }
}