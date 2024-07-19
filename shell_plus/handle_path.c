#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "main.h"
char *find_executable(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy;
	char *token;
	size_t token_length;
	size_t command_length;
	size_t full_path_length;
	char *full_path;
	char *dest;
	size_t i;
	size_t j;
	if (path == NULL || command == NULL || command[0] == '\0')
	{
	return (NULL);
	}

	path_copy = path;
	while (*path_copy)
	{
	token = path_copy;
	while (*path_copy && *path_copy != ':')
	{
	path_copy++;
	}

	token_length = path_copy - token;
	command_length = 0;
	while (command[command_length] != '\0')
	{
	command_length++;
	}
	full_path_length = token_length + 1 + command_length + 1;

	full_path = (char *)malloc(full_path_length);
	if (full_path == NULL)
	{
	return (NULL); /* Allocation error */
	}

	dest = full_path;
	for (i = 0; i < token_length; i++)
	{
	*dest++ = *token++;
	}
	*dest++ = '/';
	for (j = 0; j < command_length; j++)
	{
	*dest++ = command[j];
	}
	*dest = '\0';

	if (access(full_path, X_OK) == 0)
	{
	return (full_path);
	}

	free(full_path);

	if (*path_copy == ':')
	{
	path_copy++;
	}
	}

	return (NULL);
}

