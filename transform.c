#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	char *buffer;
	size_t bufsize = 1024;
	size_t characters;

	buffer = (char *)malloc(bufsize * sizeof(char));
	
	//input: an empty line containing just space
	if (argc == 1)
	{
		while(!feof(stdin)){
		characters = getline(&buffer, &bufsize, stdin);
		printf("You typed: '%s'\n", buffer);
		}
	}
	//input: a list of tokens
	else 
	{
		printf("You are in the wrong place");	
	}
		
	return 0;    
}
