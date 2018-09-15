/*-----------------------------------------------------
|		       transform.c
|------------------------------------------------------
|
| Compile with: gcc -o transform transform.c
|
| Author: Kelsey Cole
|
| Description: take in decimal and hexadecimal numbers
| from standard input, convert to ASCII characters and
| output to the standard output
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*strtol(), strncpy, strncmp, etc*/
#include <ctype.h> /*isdigit()*/


/*------------------------------------------------------
|                    process_input
|-------------------------------------------------------
| inputs: user_input (a char array of user input)
|  	  to_int (a char array to store converted input)
| outputs: to_int (array with proccessed user input)
|           prints processed user input to the std output
---------------------------------------------------------*/ 	

void process_input(char user_input[], char to_int[])
{
	int index = 0; /*for tracking position in char array to_int*/
	long temp;
	char temp_char;
	char *tokenized;
	char *pointer;

	/*Tokenize the user input*/
	tokenized = strtok(user_input, " ,\n");
	int flag = 1; /*for tracking the beginning and end of comments*/
	size_t sizet_one = 1;

	while(tokenized != NULL) /*traverse the tokenization*/
	{
		int length = strlen(tokenized);
		char substring[length]; 
		strncpy(substring, tokenized, sizeof(tokenized)); /*make a copy of the token
								  so it can be used by isdigit*/		
		if (flag == 1) /*if the flag is not set to indicate a comment*/
		{
			if(atoi(substring) != 0) /*if the substring is a decimal*/
			{
				temp = strtol(tokenized, &pointer, 10);	/*convert to a long*/
				temp_char = (char) temp; /*cast to a character*/
				to_int[index] = temp_char; /*store to to_int*/	
				printf("%c", to_int[index]); /*print to std output*/
			}
			else if(isxdigit(substring[0]) != 0) /*if the substring is a hexadecimal*/
			{
				temp = strtol(tokenized, &pointer, 16); /*convert to long*/
				temp_char = (char) temp; /*cast to a character*/
				to_int[index] = temp_char; /*store to to_int*/
				printf("%c", to_int[index]); /*print to std output*/	 
			}
			else if(strncmp(substring, "/", sizet_one) == 0) /*if the substring is the beginning
										of a comment*/
			{	
				flag = 0; /*set flag to indicate to a comment*/
			}
			else /*else this substring is invalid*/
			{
				printf(" Error! < %s > ", tokenized); 
			}
		}
		else if (flag == 0) /*if the comment flag is set*/
		{
			if(strpbrk(substring, "*/") != NULL) /*if this is the end of the comment*/
				flag = 1; /*set the flag back*/
		}
	
		tokenized = strtok(NULL, " ,\n"); /*go to the next token*/

		index++;
	}
}
/*----------------------------------------
|                  main                   
-----------------------------------------*/ 
int main()
{
	char buffer[1024];
	char *b = buffer;
	char stuck[1024];
	char *s = stuck;
	size_t bufsize = 1024;
	size_t characters;
	char input[1024];	

	/*read from standard input*/	
	do
	{
		characters = getline(&b, &bufsize, stdin);
		if(strcmp(buffer,stuck) != 0) 
			strcat(input, b);
		strcpy(stuck, buffer);
	} while(!feof(stdin));
	
	/*create array to store processed input*/	
	char char_to_int[100000];
	
	/*process input and print to std output*/
	process_input(input, char_to_int);


	return 0;    
}
