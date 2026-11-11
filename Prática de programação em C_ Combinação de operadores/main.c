/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{ int num1, num2, num3, soma, multiplicacao, subtracao;
float divisao;

    printf("Digite o primeiro numero:...");
        scanf("%d",&num1);
        
    printf ("Digite o segundo numero:...");
        scanf("%d", &num2);
    
    printf("Digite o terceiro numero:...");
        scanf("%d", &num3);
    
    soma = num1+num2+num3;
    printf("A soma é:...%d\n", soma);
    
    subtracao = num1-num2-num3;
    printf("A subtracao é:... %d\n", subtracao);
    
    multiplicacao = num1*num2*num3;
    printf("A multiplicacao é:... %d\n", multiplicacao);
    
    divisao = (float)num1/num2/num3;
    printf("A divisao é:... %.2f\n", divisao);
    
    if(num1>num2) {
        printf("O primeiro numero e maior que o segundo.\n");
    } else { 
        printf("O primeiro numero não é maior que o segundo numero.\n");
    }
        if(num2<num3) {
        printf("O segundo numero e menor que o terceiro numero.\n");
    } else {
        printf("O segundo numero nao e menor que o terceiro numero.\n");
    }
    
    if(num1>0 && num2 % 2 == 0) {
        printf("O primeiro numero e positivo e o segundo numero e par.\n");
    } else {
        printf("As condicoes nao foram atendidas.\n");
    }
    
 
    return 0;
}
