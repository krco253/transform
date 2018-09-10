#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_hex(char *item)
{
//TODO Write function to determine if a string is hex num
}

bool is_decimal(char *item)
{
//TODO write function to determine if string is decimal num
}

int to_int_array(char user_input[], long to_int[])
{
	int index = 0;
	char *tokenized;
	char *pointer;
	tokenized = strtok(user_input, " ,\n");

	while(tokenized != NULL)
	{
		tokenized = strtok(NULL, " ,\n");
		if(is_hex(tokenized))
			to_int[index] = strtlo(tokenized, &pointer, 16);
		else if(is_decimal(tokenized))
			to_int[index] = strtlo(tokenized, &pointer, 10);
		else
			return -1;
			
		index++;
	}

}

void int_to_char(long int_array[], char char_array[])
{
//TODO write function to convert from int array to char array
}

int main()
{
	char buffer[1024];
	char *b = buffer;
	char stuck[1024];
	char *s = stuck;
	int function_success = 0;
	size_t bufsize = 1024;
	size_t characters;
	char input[1024];	
	char * tokenized;
	long char_to_int[3000];
	char final[3000];
	/*read from standard input*/	
	do
	{
		characters = getline(&b, &bufsize, stdin);
		if(strcmp(buffer,stuck) != 0) 
			strcat(input, b);
		strcpy(stuck, buffer);
	} while(!feof(stdin));
	
	function_success = to_int_array(input, char_to_int);
	if (function_sucess == -1)
	{
		print("Invalid format!\n");
	}
	
	int_to_char(char_to_int, final);
/*	
	tokenized = strtok(input, " ,\n");
	int index = 0;

	while(tokenized != NULL)
	{
		printf("%s ", tokenized);
		tokenized = strtok(NULL, " ,\n");
		char_to_int[index] = atoi(tokenized);
		index++;
	}
*/
	
	return 0;    
}
