#include<stdio.h>
void main() {
    int i, j, lines;
    printf("Input lines : ");
    scanf("%d", &lines);

    for(i = 1; i <= lines; i++) {
        for(j = 1; j <= lines; j++) {
            printf("* ");
        }
        printf("\n");
    }
}