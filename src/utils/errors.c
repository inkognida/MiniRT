#include "../includes/minirt.h"

void error_exit(int code)
{
	if (code == -1)
		write(STDERR_FILENO, "Error: memory allocation failed\n", 32);
	exit(code);
}