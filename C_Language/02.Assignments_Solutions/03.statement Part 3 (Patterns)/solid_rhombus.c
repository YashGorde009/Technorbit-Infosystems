#include<stdio.h>
void main() {
    int i, j, n;
    printf("Input N : ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n - i; j++) { //spaces
            printf("  ");
        }
        for(j = 1; j <= n; j++) { //star
            printf("* ");
        }
        printf("\n");
    }
}