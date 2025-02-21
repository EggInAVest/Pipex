/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:05 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/06 15:01:31 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		status;

	check_args(argc);
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
	return (WEXITSTATUS(status));
}

void	child_process_in(char **argv, char **envp, int *fd)
{
	int	fd_in;

	close(fd[0]);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		close(fd[1]);
		perror_and_exit(argv[1]);
	}
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
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

char	*find_exec_path(char **envp, char **commands)
{
	char	*exec_path;
	char	*my_path;
	char	**path;

	if (ft_strchr(*commands, '/'))
		return (ft_strdup(*commands));
	my_path = find_my_path(envp);
	if (my_path == NULL)
	{
		exec_path = NULL;
		return (exec_path);
	}
	path = ft_split(my_path, ':');
	exec_path = get_path(path, commands);
	return (exec_path);
}
