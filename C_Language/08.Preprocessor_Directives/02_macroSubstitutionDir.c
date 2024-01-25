#include<stdio.h>
#define a 2+3 // this line is roughed by preprocessor and every a is replaced by it's replacement text here '10' at every a
             //  to verify compile  "gcc -save-temps 02_macroSubstitutionDir.c"
void main()
{
    int x;
    x = a * a;
    printf("%d\n", x);
}

// output : 12