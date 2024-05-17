# include <unistd.h>

int	main(void)
{
	char *argv[] = {"/bin/ls", "-a", "-l", NULL};
	execve(argv[0], argv, NULL);
}
