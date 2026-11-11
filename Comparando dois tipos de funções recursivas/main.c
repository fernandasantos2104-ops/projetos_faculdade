/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n - 2);
     }
}

int fibonacci_cauda(int n, int a, int b) {
     if (n == 0) return a;
     if (n == 1) return b;
    return fibonacci_cauda(n - 1, b, a + b);
    }
        
    
int main() {

   int n = 40;
   clock_t inicio, fim;
   double tempo_simples, tempo_cauda;
   
   inicio = clock();
   int res1 = fibonacci(n);
   fim = clock();
   tempo_simples = (double)(fim - inicio) / CLOCKS_PER_SEC;
   
   inicio = clock();
   int res2 = fibonacci_cauda(n, 0, 1);
   fim = clock();
   tempo_cauda = (double)(fim - inicio) / CLOCKS_PER_SEC;
   
   printf("Fibonacci Simples: %d | Tempo: %f segundos\n", res1, tempo_simples);
   printf("Fibonacci em Cauda: %d | Tempo: %f segundos\n", res2, tempo_cauda);

   
    return 0;
}
