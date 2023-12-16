#include<stdio.h>
void main() {
    int i, j, n1, n2;
    printf("Input N1 : ");
    scanf("%d", &n1);
    printf("Input N2 : ");
    scanf("%d", &n2);

    // firstHalf
    for(i = 1; i <= n1; i++) {
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        for(j = 1; j <= n2 -(2*i); j++) {
            printf("  ");
        }
        for(j = 1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }
// second half
    for(i = n2/2; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        for(j = 1; j <= n2 -(2*i); j++) {
            printf("  ");
        }
        for(j = 1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}