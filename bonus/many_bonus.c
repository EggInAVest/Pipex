/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:07:51 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/06 15:04:52 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_many_commands(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	int		fd_in;
	int		i;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		perror_and_exit(argv[1]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	i = 2;
	while (i < argc - 2)
		handle_middle_commands(argv, envp, i++);
	pid = fork();
	if (pid == -1)
		perror_and_exit("Fork");
	if (pid == 0)
		handle_last_command(argc, argv, envp);
	waitpid(pid, &status, 0);
	exit(WEXITSTATUS(status));
}

void	handle_middle_commands(char **argv, char **envp, int index)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		perror_and_exit("Pipe");
	pid = fork();
	if (pid == -1)
		perror_and_exit("Fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec_many(argv, envp, index);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	handle_last_command(int argc, char **argv, char **envp)
{
	int	fd_out;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		fd_out = open_file(argv[argc -1], 2);
	else
		fd_out = open_file(argv[argc -1], 1);
	if (fd_out == -1)
		perror_and_exit(argv[argc -1]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	exec_many(argv, envp, argc -2);
}

void	exec_many(char **argv, char **envp, int index)
{
	char	*exec_path;
	char	**commands;

	commands = NULL;
	commands = ft_split(argv[index], ' ');
	if (!commands || commands[0] == NULL)
		empty_command_exit(commands);
	exec_path = find_exec_path(envp, commands);
	if (exec_path == NULL)
		command_not_found(commands);
	if (access(exec_path, F_OK) != 0)
		file_not_found(commands);
	if (access(exec_path, X_OK) != 0)
		command_not_executable(commands, exec_path);
	execve(exec_path, commands, envp);
	perror(exec_path);
	ft_free_array(commands);
	free(exec_path);
	exit(126);
}
