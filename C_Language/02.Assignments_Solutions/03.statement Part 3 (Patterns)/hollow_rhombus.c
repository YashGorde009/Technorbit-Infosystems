#include<stdio.h>
void main() {
    int i, j, n;
    printf("Input N : ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= (n - i); j++) { // spaces
            printf("  ");
        }

        // hollow rectanle
        for(j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) { // stars
                printf("* ");

            } else { // spaces
                printf("  ");
            }
        }
        printf("\n");
    }
}