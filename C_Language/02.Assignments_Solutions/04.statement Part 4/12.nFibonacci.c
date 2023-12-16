// The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1
#include<stdio.h>
void main() {
    int i, rgn, current = 0, previous = 1, next;
    printf("Enter A Range & Get Fibonacci Series Till That Range But Before...\n");
    printf("Enter Range : ");
    scanf("%d", &rgn);

    if(rgn <= 0){
        printf("Invalid Range : Range Must Be An Positive Integer\n");
    }
    else
    {
    printf("%d %d ", current, previous);
    for(i = 1; (next = current + previous) <= rgn - 2; i++) // minusing 2 from rgn bcoz already printed first two terms of the series
    {
        printf("%d ", next);
        current  = previous;
        previous = next; 
    }
    }
}