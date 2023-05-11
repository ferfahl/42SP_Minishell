#include "minishell.h"

t_minishell	g_data;

int main(void)
{
	char	**cmd;
	int		fd;

	fd = ft_here_doc("eof");
	// fd = open("teste", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	cmd = malloc(2 * sizeof(char *));
	cmd[0] = strdup("/bin/cat");
	cmd[1] = NULL;
	close(fd);
	execve(cmd[0], cmd, NULL);
}
