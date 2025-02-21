/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:11:20 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 18:41:25 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("Too few arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc == 5)
		handle_two_commands(argv, envp);
	else if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		handle_here_doc(argc, argv, envp);
	else if (argc >= 6)
		handle_many_commands(argc, argv, envp);
	return (0);
}

void	handle_two_commands(char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		perror_and_exit("Pipe");
	pid1 = fork();
	if (pid1 == -1)
		perror_and_exit("Fork");
	if (pid1 == 0)
		child_process_in(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		perror_and_exit("Fork");
	if (pid2 == 0)
		child_process_out(argv, envp, fd);
	close_fds(fd);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	exit(WEXITSTATUS(status));
}

void	child_process_in(char **argv, char **envp, int *fd)
{
	int	fd_in;

	close(fd[0]);
	fd_in = open_file(argv[1], 0);
	if (fd_in == -1)
		perror_and_exit(argv[1]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute(argv, envp, 1);
}

void	child_process_out(char **argv, char **envp, int *fd)
{
	int	fd_out;

	close(fd[1]);
	fd_out = open_file(argv[4], 1);
	if (fd_out == -1)
		perror_and_exit(argv[4]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	execute(argv, envp, 2);
}

void	execute(char **argv, char **envp, int child)
{
	char	*exec_path;
	char	**commands;

	commands = NULL;
	if (child == 1)
		commands = ft_split(argv[2], ' ');
	if (child == 2)
		commands = ft_split(argv[3], ' ');
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
