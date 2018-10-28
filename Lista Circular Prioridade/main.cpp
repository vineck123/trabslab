//---------------------------------------------------------------------------------|
#include <cstdio> //                                                               |
#include <cstdlib> //                                                              |
#include <unistd.h> //                                                             |
#include <cstring> //                                                              |
//---------------------------------------------------------------------------------|
//protótipos abaixo                                                                |
//---------------------------------------------------------------------------------|
struct patient {
    int priority;
    int id;
    patient * next;
    patient * end;
    char name[25];
}; //                                                           |
//---------------------------------------------------------------------------------|
//prototypes                                                                       |
void menu(int &option, int &size, patient*&first); //                              |
void add_node(patient*&first, int &size); //                                       |
patient* get_data (patient*&new_node, patient * first); //                         |
void add_top (patient*&first, patient*&new_node); //                               |
void add_middle(patient*&before, patient*&new_node); //                            |
void show_list (patient*&first, int size); //                                      |
void attend (patient*&first, int size); //                                         |
void add_end(patient*&first,patient*&new_node); //                                 |
void swap(patient *&start); //                                                     |
//---------------------------------------------------------------------------------|
//                                                                                 |
//---------------------------------------------------------------------------------|
//função principal abaixo                                                          |
//---------------------------------------------------------------------------------|
int main() {
    int size=0, option;
    patient * first;
    first = nullptr;

    system("clear");
    do{
        menu(option, size, first);
    }while(option != 0);
} //                                                                |
//---------------------------------------------------------------------------------|
//procedimento que faz o menu                                                      |
void menu(int &option, int &size, patient*&first) {
    printf("Informe o que deseja fazer:\n");
    printf("1)Adicionar pacientes.\n");
    printf("2)Exibir lista com pacientes.\n");
    printf("3)Atender lista.\n");
    printf("0)Sair.\n\n\n");
    fflush(stdin);
    scanf("%d", &option);
    system("clear");

    switch(option) {
        case 1:
            add_node(first, size);
            break;
        case 2:
            show_list(first, size);
            break;
        case 3:
            attend(first, size);
            break;
        case 0:
            break;
        default:
            printf("Esta funcionalidade não existe.\n");
    }
    system("clear");
} //                         |
//---------------------------------------------------------------------------------|
//procedimento que adiciona um nó                                                  |
void add_node(patient*&first, int &size){
    patient * new_node, *actual, *before;

    actual = first;
    new_node = (patient*) calloc (1,sizeof(patient));

    new_node = get_data(new_node, first);

    //aqui o código checa se o primeiro nó está vazio, e aloca o novo nó à ele caso seja verdadeiro
    if(first == nullptr) {
        first = new_node;
        first->next = new_node;
        first->end = first;
    }else if(first->next == first){ //aqui é caso haja somente um nó, ele verifica se é < ou <=
        if(new_node->priority > first->priority) {
            add_top(first, new_node);
        }else if(new_node->priority <= first->priority) {
            add_end(first, new_node);
        }
    }else {
        patient *last;
        last = first->end;
        int i = 0;

        if (new_node->priority <= last->priority) {
            add_end(first, new_node);
        }else if(new_node->priority > first->priority) {
            add_top(first, new_node);
        }else{
            while(new_node->priority <= actual->priority) {
                before = actual;
                actual = actual->next;
                i++;
            }
            add_middle(before, new_node);
        }
    }
    size++;

} //                                   |
//---------------------------------------------------------------------------------|
//função de receber dados                                                          |
patient* get_data (patient*&new_node, patient * first) {

    patient * last;
    last = first;

    if (first == nullptr) {
        new_node->id = 1;
    }else{
        new_node->id = last->id +1;
    }

    do {
        printf("Digite a prioridade, sendo 1 comum e 5 a mais alta:\n");
        fflush(stdin);
        scanf("%d", &new_node->priority);
    }while(new_node->priority < 1 || new_node->priority > 5);
    printf("Digite o primeiro nome do paciente:\n");
    scanf("%s", new_node->name);
    sleep(1);
    system("clear");
    return new_node;
} //                    |
//---------------------------------------------------------------------------------|
//procedimento de adicionar no começo                                              |
void add_top (patient*&first, patient*&new_node) {
    patient * swap_aux;

    swap_aux = first;
    first = new_node;
    new_node = swap_aux;
    first->next = new_node;
    new_node->next = swap_aux->next;
    first->end = new_node;
} //                          |
//---------------------------------------------------------------------------------|
<<<<<<< HEAD
=======
//procedimento que adiciona no fim                                                 |
//---------------------------------------------------------------------------------|
>>>>>>> dccd7a1504f0d3268b1d734b5d10416e7bd47bd9
//procedimento que adiciona no meio da lista                                       |
void add_middle(patient*&before, patient*&new_node) {
    new_node->next = before->next;
    before->next = new_node;
} //                       |
//---------------------------------------------------------------------------------|
//procedimento que exibe a lista                                                   |
void show_list (patient*&first, int size) {

    patient * actual;
    actual = first;


    while(size > 0) {
        printf("------------------------------------------------\n");
        printf("Nome do paciente: %s.\n", actual->name);
        printf("Código do paciente: %d.\n", actual->id);
        printf("Prioridade do paciente: %d.\n", actual->priority);
        if(size == 1) {
            printf("------------------------------------------------\n");
        }
        actual=actual->next;
        size--;
    }
    sleep(10);
    system("clear");
} //                                 |
//---------------------------------------------------------------------------------|
//procedimento que faz o atendimento dos pacientes                                 |
void attend(patient*&first, int size) {
    char aux_name[11] = {' ','-', 'A', 'T' , 'E', 'N', 'D', 'I', 'D', 'O'};
    int tempo;
    char verify='s';
    while(size > 0 && verify == 's' || verify == 'S') {

        tempo = first->priority * 2;

        printf("------------------------------------------------\n");
        printf("Nome do paciente: %s\n", first->name);
        printf("Será atendido por %d segundo(s)\n", first->priority*2);
        printf("Preferência: %d.\n", first->priority);
        printf("Código do paciente: %d.\n", first->id);
        strcat(first->name, aux_name);
        printf("------------------------------------------------\n");
        sleep(tempo);
        size--;
        swap(first);
        printf("\nDeseja atender outro paciente? S-N.\n");
        printf("Ainda existe(m) %d paciente(s) na fila.\n\n", size);
        scanf(" %c", &verify);
        system("clear");
    }
} //                                     |
//---------------------------------------------------------------------------------|
//procedimento que adiciona no fim                                                 |
void add_end(patient*&first,patient*&new_node) {
    patient * last;
    last = first->end;

    last->next = new_node;
    new_node->next = first;
    first->end = new_node;
} //                            |
//---------------------------------------------------------------------------------|
void swap(patient *&start) {
    patient *aux=nullptr,*aux1=nullptr;
    aux=start;
    while(aux->next!=start) {
        aux1=aux;
        aux=aux->next;
    }
    aux1->next=start;
    aux->next=start->next;
    start->next=aux;
    start=aux;
} //                                                |
//---------------------------------------------------------------------------------|
