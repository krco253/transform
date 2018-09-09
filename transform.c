#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	char buffer[1024];
	char *b = buffer;
	char stuck[1024];
	char *s = stuck;
	size_t bufsize = 1024;
	size_t characters;
	char input[1024];	
	char * tokenized;
	//read from standard input	
	do
	{
		characters = getline(&b, &bufsize, stdin);
		if(strcmp(buffer,stuck) != 0) 
			strcat(input, b);
		strcpy(stuck, buffer);
	} while(!feof(stdin));
	
//	tokenized = strtok(input, " \n");
	printf("new string: '%s'\n", input);
	
	return 0;    
}
