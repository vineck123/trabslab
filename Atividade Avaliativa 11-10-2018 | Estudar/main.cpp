#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

struct aluno {
    int mat=0;
    char nome[80];
    float nota;
    char sexo;
    struct aluno* prox;
};

//declaração de protótipos
void adicionar(aluno * &primeiro);
void pegar_dados(aluno * &add);
void adiciona_fim(aluno * &novo, aluno * &primeiro);
aluno* percorrer(aluno *&primeiro, int matricula);
aluno* dividir_lista(aluno* &primeiro, int matricula);
void exibir (aluno* &primeiro);
//---------------------------------------------------------------

int main() {

    aluno * primeiro;
    primeiro = NULL;
    int op = 0;

    do{
        system("clear");
        printf("Selecione a opção:\n1-)Adicionar aluno.\n2-)Exibir.\n3-)Dividir a lista\n0-)Sair.\n\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                adicionar(primeiro);
                break;
            case 2:
                system("clear");
                exibir(primeiro);
                sleep(5);
                break;
            case 3:
                system("clear");
                int matricula;
                aluno * controle;
                printf("Digite a matricula que deseja procurar para dividir.\n");
                scanf("%d", &matricula);
                controle = dividir_lista(primeiro, matricula);
                if(controle == NULL) {
                    printf("Aluno não existente na lista ou é o último aluno.\n");
                }else{
                    printf("\n\nLista original:\n");
                    exibir(primeiro);
                    printf("\n\nSegunda Lista:\n");
                    exibir(controle);
                }
                sleep(5);
                break;
        }
    }while(op!=0);
    free(primeiro);
}

void adicionar(aluno * &primeiro) {
    aluno * novo, *aux, *aux_troca_pont;

    novo = (aluno*) calloc(1,sizeof(aluno));
    system("clear");
    if(novo == NULL) {
        printf("Erro ao alocar um novo nó\n");
    }else{
        pegar_dados(novo);
        if (primeiro == NULL) {
            novo->prox = NULL;
            primeiro = novo;
            /*esse if eh pra fazer com que na primeira vez que o programa seja executado,
            os dados sejam salvos na primeira posição*/
        }else{
            //variável de controle, a descrição dessa função percorrer está onde ela foi codificada
            aux = percorrer(primeiro,novo->mat);
            if (aux != NULL) {
                //se está entre dois nós, ele faz basicamente a função de adicionar no meio
                novo->prox = aux->prox;
                aux->prox = novo;
            }else if (aux == NULL && novo->mat <= primeiro->mat) {
                //esse else if é para adicionar no começo da lista, caso ele seja o menor nó de matricula
                aux_troca_pont = primeiro;
                primeiro = novo;
                novo->prox = aux_troca_pont;
            }else{
                //ele seja o maior nó de matricula
                adiciona_fim(novo,primeiro);
            }
        }
    }
}

//procedimento simples de exibir nós
void exibir(aluno * &primeiro) {
    aluno * atual;

    atual = primeiro;

    while(atual != NULL) {
        printf("--------------------------------\n");
        printf("Matricula: %d\n", atual->mat);
        printf("Nome: %s\n", atual->nome);
        printf("Nota: %.1f\n", atual->nota);
        printf("Sexo: %c\n", atual->sexo);

        if(atual->prox == NULL) {
            printf("--------------------------------\n");
        }
        atual = atual->prox;
    }

}

//procedimento de pegar dados
void pegar_dados(aluno * &add) {
    system("clear");
    fflush(stdin);
    printf("Digite a matricula do novo aluno.\n");
    scanf("%d", &add->mat);
    printf("\nDigite o nome do aluno.\n");
    scanf("%s", add->nome);
    printf("\nDigite a nota do aluno.\n");
    scanf("%f", &add->nota);
    printf("\nDigite o sexo do aluno.\n");
    scanf(" %c", &add->sexo);
}

//essa função de percorrer para que antes de posicionar o novo no na lista, ele procura se o nó de matricula esta entre dois nós
aluno* percorrer(aluno *&primeiro, int matricula) {
    aluno * atual, * aux;

    aux = NULL;

    atual = primeiro;

    while(atual != NULL) {
        if (matricula > atual->mat) {
            aux = atual;
        }
        atual = atual->prox;
    }

    return aux;
}

//procedimento simples de adicionar no fim
void adiciona_fim(aluno* &novo, aluno* &primeiro){

    aluno* ultimo;

    ultimo = primeiro;

    while(ultimo->prox != NULL){
        ultimo = ultimo->prox;
    }
    ultimo->prox = novo;
    novo->prox = NULL;
}

//nessa função, ele percorre até o nó de matrícula desejado e divide a lista em dois, sendo o retorno o começo da 2ª lista
aluno* dividir_lista(aluno* &primeiro, int matricula) {
    aluno * atual, * aux;

    aux = NULL;
    atual = primeiro;

    while(atual != NULL) {
        if(matricula == atual->mat) {
            aux = atual->prox;
            atual->prox = NULL;
            return aux;
        }
        atual = atual->prox;
    }
    return aux;
}
