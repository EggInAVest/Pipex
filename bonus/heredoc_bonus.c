/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:07:40 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 17:19:40 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_here_doc(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	int		fd_in;
	int		i;

	fd_in = prep_here_doc(argv);
	if (fd_in == -1)
		perror_and_exit(argv[1]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	i = 3;
	while (i < argc - 2)
		handle_middle_commands(argv, envp, i++);
	pid = fork();
	if (pid == -1)
		perror_and_exit("Fork");
	if (pid == 0)
		handle_last_command(argc, argv, envp);
	waitpid(pid, &status, 0);
	unlink("here_doc_temp");
	exit(WEXITSTATUS(status));
}

int	prep_here_doc(char **argv)
{
	char	*line;
	int		fd_in;

	fd_in = open_file("here_doc_temp", 2);
	if (fd_in == -1)
		perror_and_exit("here_doc_temp");
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if ((ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
				&& line[ft_strlen(argv[2])] == '\n') || (line == NULL))
		{
			free(line);
			close(fd_in);
			return (open_file("here_doc_temp", 0));
		}
		ft_putstr_fd(line, fd_in);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd_in);
	return (open_file("here_doc_temp", 0));
}
