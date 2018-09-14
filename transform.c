#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isdigit()

/*
int is_number_string(const char *item)
{
	while(*item)
	{
		if ((isdigit(*item++) == 0))
			return 0;
	}
	return 1;
}

int is_hex(char *item)
{
	char *compare = "0x";
	if ((item[0] == compare[0]) && (item[1] == compare[1]))
		return 1;
	else return 0;
	
}

int is_decimal(char *item)
{
	int only_num = is_number_string(item);
	if (only_num ==0)
		return 0;
	else return 1;
}
*/
int to_int_array(char user_input[], char to_int[])
{
	int index = 0;
	long temp;
	char temp_char;
	char *tokenized;
	char *pointer;
	char *error = "Error";
	tokenized = strtok(user_input, " ,\n");
	
	while(tokenized != NULL)
	{
		int length = strlen(tokenized);
		char substring[length];
		strncpy(substring, tokenized, sizeof(tokenized));
	
		if(atoi(substring) != 0)
		{
			temp = strtol(tokenized, &pointer, 10);	
			temp_char = (char) temp;
			to_int[index] = temp_char;	
		}
		else if(isxdigit(substring[0]) != 0)
		{
			temp = strtol(tokenized, &pointer, 16);
			temp_char = (char) temp;
			to_int[index] = temp_char;
			
		}
		else
			return 0;
	
//		printf("%s ", tokenized);
		tokenized = strtok(NULL, " ,\n");
		index++;
	}

	return 1;
}

/*void int_to_char(long int_array[], char char_array[])
{
//TODO write function to convert from int array to char array
	int index = 0;
	int int_array_size;
	int_array_size = *(&int_array + 1) - int_array;

	for (int i = 0; i < int_array_size; i++)
	{
		char char_temp;
		long int_temp = int_array[index];
		char_temp = (char) int_temp;
		char_array[index] = char_temp;
		index++;
	}


}*/

void print_char_array(char char_array[])
{
	int index = 0;

	while (index < strlen(char_array))
	{
		printf("%c ", char_array[index]);
		index++;
	}
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
	char char_to_int[10000];
	char *err = "Error";
	char *checker;
	/*read from standard input*/	
	do
	{
		characters = getline(&b, &bufsize, stdin);
		if(strcmp(buffer,stuck) != 0) 
			strcat(input, b);
		strcpy(stuck, buffer);
	} while(!feof(stdin));
	
	function_success = to_int_array(input, char_to_int);
	if (function_success == 0)
	{
		printf("Error: Invalid format!\n");
		return 0;
	}

	print_char_array(char_to_int);	
/*	int_to_char(char_to_int, final);*/

//	printf("%s ", char_to_int);
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
