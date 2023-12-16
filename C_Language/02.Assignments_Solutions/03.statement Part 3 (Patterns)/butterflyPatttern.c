#include<stdio.h>
void main() {
    int i, j, n;
    printf("Input N : ");
    scanf("%d", &n);
    //First Half
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) { // star - i
            printf("* ");
        }
        for(j = 1; j <= 2 * (n - i); j++) { // spaces - 2 * (n - i)
            printf("  ");
        }
        for(j = 1; j <= i; j++) { // star - i
            printf("* ");
        }
        printf("\n");
    }
    for(i = n; i >= 1; i--) {
        for(j = 1; j <= i; j++) { // star - i
            printf("* ");
        }
        for(j = 1; j <= 2 * (n - i); j++) { // spaces - 2 * (n - i)
            printf("  ");
        }
        for(j = 1; j <= i; j++) { // star -i
            printf("* ");
        }
        printf("\n");
    }
}