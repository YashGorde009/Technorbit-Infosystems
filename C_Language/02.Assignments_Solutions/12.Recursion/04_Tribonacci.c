#include<stdio.h>

int tribonacci(int);

void main()
{
    int n = 4; // n_th term
    
    printf("Tribonacci %dth Term = %d", n, tribonacci(n));

}

int tribonacci(int n)
{
    if(n == 0)
        return 0;

    if(n == 1 || n == 2)
        return 1;

    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3); 
}