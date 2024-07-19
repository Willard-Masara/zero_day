#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/* Custom string comparison function */
int string_compare(const char *str1, const char *str2);

/**
 * prompt - an infinite loop that runs the shell.
 * Return: nothing.
 */



void prompt(void)
{
	char *address = NULL;
	size_t size = 0;
	const char *message = "#cisfun$ ";
	ssize_t input;
	char *command;
	char *arguments[64]; /*Max number of arguments, adjust as needed*/
	int arg_index = 0;

	while (1)
	{
	write(STDOUT_FILENO, message, 9);
	input = getline(&address, &size, stdin);

	if (input == -1)
	{
	if (address != NULL)
	/*free(address);*/

	if (isatty(STDIN_FILENO))
	{
	write(STDOUT_FILENO, "\n", 1);
	break;
	}
	}

	if (input > 0 && address[input - 1] == '\n')
	{
	address[input - 1] = '\0';
	input--;
	}

	/*Tokenize the command and arguments*/
	command = strtok(address, " \t\n");
	arg_index = 0;
	while ((arguments[arg_index] = strtok(NULL, " \t\n")) != NULL)
	{
	arg_index++;
	}
	arguments[arg_index] = NULL; /*Set the last element of the arguments array to NULL*/

	/* Handle the built-in "exit" command */
	if (string_compare(command, "exit") == 0)
	{
	handle_exit();
	}
	/* Handle the built-in "env" command */
	else if (string_compare(command, "env") == 0)
	{
	handle_env();
	}
	/* Execute other commands */
	else
	{
	handle_arguments(command, arguments);
	}

	free(address);
	}
}
/* Custom string comparison function */
int string_compare(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
	str1++;
	str2++;
	}
	return (*str1 - *str2);
}

