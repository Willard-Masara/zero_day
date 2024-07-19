#include <unistd.h>
#include "main.h"
extern char **environ; /*External variable that holds the environment variables*/

void handle_env(void)
{
	int i = 0;

	while (environ[i])
	{
	char *current_var = environ[i];
	while (*current_var)
	{
	write(STDOUT_FILENO, current_var, 1);
	current_var++;
	}
	write(STDOUT_FILENO, "\n", 1);
	i++;
	}
}

