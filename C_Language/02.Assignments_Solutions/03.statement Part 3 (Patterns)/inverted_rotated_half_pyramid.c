#include<stdio.h>
void main() {
    int i, j, n;
    printf("Input N : ");
    scanf("%d", &n);
    // outer loop
    for(i = 1; i <= n; i++) {
        // inner loop
        for(j = 1; j <= n - i; j++) { // spaces
                printf("  ");
        }
        for(j = 1; j <= i; j++) { // stars
                printf("* ");
        }
        printf("\n");
    }
}