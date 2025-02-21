/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:06:16 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 18:50:11 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	perror_and_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	empty_command_exit(char **commands)
{
	ft_putstr_fd("Command '' not found\n", 2);
	free(commands);
	exit(127);
}

void	command_not_found(char **commands)
{
	ft_putstr_fd(*commands, 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_free_array(commands);
	exit(127);
}

void	command_not_executable(char **commands, char *exec_path)
{
	perror(exec_path);
	ft_free_array(commands);
	free(exec_path);
	exit(126);
}

void	file_not_found(char **commands)
{
	perror(*commands);
	ft_free_array(commands);
	exit(127);
}
