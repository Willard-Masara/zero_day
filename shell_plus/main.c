#include <unistd.h>
#include "main.h"

int main(int argc, char **argv)
{
	int i;
	if (argc > 1)
	{

	for (i = 1; i < argc; i++)
	{
	const char *arg = argv[i];
	size_t arg_len = 0;
	while (arg[arg_len])
	arg_len++;
	write(STDOUT_FILENO, arg, arg_len);
	write(STDOUT_FILENO, "\n", 1);
	}
	}
	else
	{
	prompt();
	}

	return (0);
}

