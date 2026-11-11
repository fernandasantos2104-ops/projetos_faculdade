/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 5
typedef struct No {
    char usuario[50];
    char senha[50];
    struct No* prox;
} No;

No* tabelaHash[TAMANHO_TABELA];

void iniciarTabela() {
    int i;
    for (i = 0; i < TAMANHO_TABELA; i++) {
        tabelaHash[i] = NULL;
    }
}
    
int funcaoHash(const char* usuario) {
    return usuario[0] % TAMANHO_TABELA;
}
void inserir(const char* usuario, const char* senha) {
    int indice = funcaoHash(usuario);

No* novoNo = (No*)malloc(sizeof(No));
if (novoNo == NULL) {
    printf("Erro de alocacao de memoria!\n");
    return;
}

strcpy(novoNo->usuario, usuario);
strcpy(novoNo->senha, senha);

novoNo->prox = tabelaHash[indice];
tabelaHash[indice] = novoNo;

printf("Utilizador \"%s\" inserido da posicao %d da tabela hash.\n", usuario, indice);
}

void buscar(const char* usuario) {
    int indice = funcaoHash(usuario);
    No* atual = tabelaHash[indice];
    
while (atual != NULL) {
    if (strcmp(atual->usuario, usuario) == 0) {
        printf("\n[SUCESSO] utilizador \"%s\" encontrado! Senha: \"%s\" (Posicao %d\n", atual->usuario, atual->senha, indice);
        return;
    }
    
     atual = atual->prox;
    
}
printf("\n[AVISO] Utilizador \"%s\" nao encontrado na tabela.\n", usuario);
}

int main() {
    iniciarTabela();
    
    printf("--- REGISTRO DE UTILIZADORES E SENHAS ---\n");
    
    inserir("ana", "senha123");
    inserir("carlos", "segredo99");
    inserir("amanda", "abc456");
    inserir("beatriz", "xyz789");
    
    printf("\n--- TESTANTO BUSCAS NA TABELA HASH ---\n");
    
    buscar("amanda");
    buscar("carlos");
    buscar("joao");
    
    return 0; 
}
