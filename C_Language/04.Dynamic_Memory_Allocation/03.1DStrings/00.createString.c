#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int size = 1, i;
    char *str = NULL, ch;
    str = (char*)malloc(sizeof(char));
    *(str + 0) = '\0';

    printf("Enter String : \n");

	i = 0;
    do{
		scanf("%c", &ch);
		if(ch != '\n')
		{
			size++;
			str = (char*)realloc(str, size);
			*(str + i) = ch;
			*(str + i + 1) = '\0';
			i++;
		}
    }while(ch != '\n');

    printf("%s", str);



}