#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
void handle_arguments(const char *command, char *const arguments[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	/* Child process */

	/* Replace the current process image with the new command */
	execvp(command, arguments);

	/* If execvp returns, it means the command is unknown or failed to execute */
	perror("Error");
	exit(EXIT_FAILURE);
	}
	else
	{
	/* Parent process */
	waitpid(pid, &status, 0);
	}
}

