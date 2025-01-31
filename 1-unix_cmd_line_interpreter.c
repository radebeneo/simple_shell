#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define max_cmd_len 100
#define prompt "> "

/**
 * main - Simple UNIX command line interpreter (shell)
 * Return: 0
 */
int main(void)
{
	char cmd[max_cmd_len];
	pid_t pid;
	int status;

	while (1)
	{
		printf(prompt);
		fflush(stdout);

		if (fgets(cmd, max_cmd_len, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		cmd[strcspn(cmd, "\n")] = 0;

		if (strlen(cmd) == 0)
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		else if (pid == 0)
		{
			execlp(cmd, cmd, NULL);
			fprintf(stderr, "simple_shell: %s: command not found\n", cmd);
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}

	return (0);
}
