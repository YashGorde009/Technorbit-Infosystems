#include <stdio.h>
void main()
{
   int i, j, totRows, totCols; 
   printf("\nInput totRows : ");
   scanf("%d", &totRows); 
   printf("\nInput totCols : ");
   scanf("%d", &totCols);

   for(i = 1; i <= totRows; i++) { // outer loop
    for(j = 1; j <= totCols; j++) { // inner loop
        // cell - (i,j)
        if(i == 1 || i == totRows || j == 1 || j == totCols) { // boundary cells
            printf("* ");
        } else {
            printf("  ");
        }
    }
    printf("\n");
   }
}