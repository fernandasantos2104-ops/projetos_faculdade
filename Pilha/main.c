/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No { 
    char operacao[50];
    struct No* prox;
} No;

int estaVazia(No* topo) {
    return (topo == NULL);
}

void push(No** topo, const char* descricaoOperacao) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

strcpy (novoNo->operacao, descricaoOperacao);
novoNo->prox = *topo;
*topo = novoNo;
printf("Operacao \"%s\" empilhada com sucesso!\n", descricaoOperacao);
}

void pop(No** topo) {
    if (estaVazia(*topo)) {
        printf("\nA pilha esta vazia! Nao ha operacoes para desfazer.\n");
        return;
    }
    
    No* temp = *topo;
    printf("\nA desfazer operacao: %s\n", temp->operacao);
    
    *topo = temp->prox;
    free(temp);
}

void listarPilha(No* topo) {
    if (estaVazia(topo)) {
        printf("\nO historico de operacoes esta vazio.\n");
        return;
    }
    
printf("\n--- HISTORICO DA CALCULADORA (TOPO AO FUNDO)---\n");
No* atual = topo;
while (atual != NULL) {
    printf("-> %s\n", atual->operacao);
    atual = atual->prox;
}
printf("-----------------------------\n");
    }
int main() {
    No* pilhaHistorico = NULL;
    
    push(&pilhaHistorico, "Soma:10 + 5");
    push(&pilhaHistorico, "multiplicacao: 4 * 2");
    push(&pilhaHistorico, "Raiz quadrada: 9");
    
    listarPilha(pilhaHistorico);
    
    pop(&pilhaHistorico);
    
    listarPilha(pilhaHistorico);
    
    return 0;
}

