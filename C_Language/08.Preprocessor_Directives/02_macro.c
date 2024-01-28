#include<stdio.h>
#define max(a, b) a > b ? a : b
void main() 
{
    int ans;
    ans = max(10, 20);
    printf("Maximum Between Given Numbers Is : %d\n", ans);
}

/*
jar symbol la parameter ale tar 'macro' ani jar symbol la parameter nai ale tar 'symbolic constant'
macro -> je replacement text asel, jar te execute honar asel tar tyle macro mhantat (symbol with parameters / funtion wise substition)
symbolic constant -> je replacement text asel, jar te execute nahi honar asel tar tyle macro mhantat (symbol without parameters / object wise substition)
*/