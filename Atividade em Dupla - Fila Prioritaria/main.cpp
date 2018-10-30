#include <cstdio>
#include <cstdlib>
#include <unistd.h>

/* TRABALHO EM DUPLA DE FILA PRIORITÁRIA - LEONARDO LOPES LOTAIF & VINICIUS NUNES*/




// Estrutura da Fila
struct banco{
    bool prioridade;
    int cadastro;
    banco * proximo;
};

// Função para exibição da lista
void exibir(banco * &primeiro) {
    // Ponteiro para percorrer a lista
    banco * atual;
    // Transcreve a lista para não perder sua referência
    atual = primeiro;
    // Laço para percorrer e exibir
    while(atual != NULL) {
        printf("Cadastro: %d  ", atual->cadastro);

        // Identificação de prioridade
        if(atual->prioridade) {
            printf("Preferencial: SIM\n\n");
        }else{
            printf("Preferencial: NAO\n\n");
        }
        printf("\n---------------------------------------\n\n");

        atual = atual->proximo;
    }
}

// Função para acrescentar na lista
void receber_dados(banco *&primeiro){

    char validacao;
    banco *novo, *atual;

    // Alocação dos nós
    novo = (banco*)calloc(1, sizeof(banco));

    // Transcreve a lista para não perder sua referência
    atual = primeiro;

    // Recepção de dados
    if(novo == NULL){
        printf("Erro para criar novo paciente.\n");
    }else{
        printf("Tem prioridade? S/N: ");
        scanf(" %c", &validacao);
        if(validacao == 'S' || validacao == 's'){
            novo->prioridade = true;
        }else{
            novo->prioridade = false;
        }
        printf("Cadastro do Paciente: ");
        scanf("%d", &novo->cadastro);

        // Controle de lista vazia
        if(primeiro == NULL) {
            primeiro = novo;
            novo->proximo = NULL;
        }else{
            while(atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
            novo->proximo = NULL;
        }
    }
    sleep(5);
    system("clear");
}

// Função para atender a lista e desinfileirar os nós
void atender(banco *& primeiro) {

    banco *aux, *anterior, *atual, *troca;
    int i = 0;
    atual = primeiro;

    // Estrutura para atender os requisitos de prioridade
    while(primeiro != NULL) {
        // Verificação de a cada 3 comuns, um atendimento tem que ser preferencial
        if(i < 3) {
            // Atendimento prioritário
            if(primeiro->prioridade == true) {
                printf("Paciente preferencial atendido na fila comum.\n\n");
                i = 0;
            }
            // Caso não alcance 3 comuns, continue removendo comuns por ordem de chegada na lista
            printf("Paciente COMUM atendido!\n");
            printf("Cod: %d", primeiro->cadastro);
            aux = primeiro;
            primeiro = primeiro->proximo;
            free(aux);
            i++;
            sleep(5);
            system("clear");
        }else{
            // Transcreve a lista para não perder sua referência
            atual = primeiro;
            // Estrutura para achar um nó com prioridade, e colocá-lo em atendimento
            if(i == 3 && primeiro->prioridade == false) {
                while(atual->prioridade == false) {
                    anterior = atual;
                    atual = atual->proximo;
                }
                aux = atual;
                if(atual->proximo != NULL) {
                    printf("Paciente PREFERENCIAL atendido!\n");
                    printf("Cod: %d", atual->cadastro);
                    anterior->proximo = atual->proximo;
                }else if (atual->proximo == NULL){
                    printf("Paciente PREFERENCIAL atendido!\n");
                    printf("Cod: %d", atual->cadastro);
                    anterior->proximo = NULL;
                }
            }

            free(aux);
            i = 0;
            printf("\n");
            sleep(5);
            system("clear");
        }
    }
}


int main(int argc, char** argv) {

    // Ponteiro de lista
    banco * primeiro;

    // Alocação inicial
    primeiro = NULL;

    int op = 0;

    // Menu de Opções
    do{

        printf("Digite a opcao escolhida:\n1)Adicionar paciente\n2)Atender a lista ja feita.\n3)Exibir.\n\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                receber_dados(primeiro);
                break;
            case 2:
                atender(primeiro);
                break;
            case 3:
                exibir(primeiro);
        }

    }while(op != 0);
    return 0;
}
