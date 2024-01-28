//write macro to find square and cube of a number
#include<stdio.h>
#define square(a) ((a)*(a))
#define cube(a) (square(a)*(a)) // nested macro

int main() {
    int num, sq, cb;
    puts("Enter Number : ");
    scanf("%d", &num);
    sq = square(num);
    cb = cube(num);
    printf("Square : %d Cube : %d\n", sq, cb);
    return 0;
}
