/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
    
{
    int numero, soma = 0;

    printf("Digite um numero:...");
    scanf("%d", &numero);

    while(numero != 0)
    {
    soma = soma + numero;
    
    
        printf("Digite outro numero, ou 0 para sair:...");
        scanf("%d", &numero);
    }
    
    printf("Resultado da soma, %d\n", soma );
    
    return 0;
}
