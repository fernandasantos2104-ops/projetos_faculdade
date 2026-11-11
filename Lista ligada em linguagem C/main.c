/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { 
    int id;
    char descricao[100];
    struct Node* prox;
} Node;

void inserirTarefa(Node** cabeca, int id, const char* desc) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->id = id;
    strcpy(novoNo->descricao, desc);
    novoNo->prox = NULL;
    
if (*cabeca == NULL) {
    *cabeca = novoNo;
} else {
    Node* atual = *cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    atual->prox = novoNo;
}
printf("Tarefa %d inserida com sucesso!\n", id);
}
void listarTarefas(Node* cabeca) {
    if (cabeca == NULL) {
        printf("\nA lista de tarefas esta vazia.\n");
        return;
    }
    
    printf("\n--- LISTA DE TAREFAS ---\n");
    Node* atual = cabeca;
    while (atual != NULL) {
        printf("ID: %d | Descricao: %s\n", atual->id, atual->descricao);
        atual = atual->prox;
    }
    
    printf("------------------------\n");
}
void removerTarefa(Node** cabeca, int idParaRemover) {
    if (*cabeca == NULL) {
        printf("\nA lista esta vazia, nao ha o que remover.\n");
        return;
    }
    
    Node* atual = *cabeca;
    Node* anterior = NULL;

if (atual->id == idParaRemover) {
    *cabeca = atual->prox;
    free(atual);
    printf("Tarefa com ID %d removida com sucesso!\n", idParaRemover);
    return;
}
while (atual != NULL && atual->id != idParaRemover) {
    anterior = atual;
    atual = atual->prox;
}
if (atual == NULL) {
    printf("Tarefa com ID %d nao encontrada.\n", idParaRemover);
    return;
}
anterior->prox = atual->prox;
free(atual);
printf("Tarefa com ID %d removida com sucesso!\n", idParaRemover);
}
int main() {
    Node* minhaLista = NULL; 
    
    inserirTarefa(&minhaLista, 1, "Estudar estrutura de dados");
    inserirTarefa(&minhaLista, 2, "Fazer o trabalho pratico de C");
    inserirTarefa(&minhaLista, 3, "Revizer a normalizacao de banco de dados");
    
    listarTarefas(minhaLista);
    
    printf("\n--- A REMOVER TAREFA 2 ---\n");
    removerTarefa(&minhaLista, 2);
    
    listarTarefas(minhaLista);
    
    return 0;
    
}

