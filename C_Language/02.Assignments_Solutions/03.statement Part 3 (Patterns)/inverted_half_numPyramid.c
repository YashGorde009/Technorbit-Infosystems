#include<stdio.h>
void main() {
    int i, j, n;
    printf("Input N : ");
    scanf("%d", &n);
    // outer loop
    for(i = 1; i <= n; i++) {
        // inner loop
        for(j = 1; j <= n - i + 1; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}