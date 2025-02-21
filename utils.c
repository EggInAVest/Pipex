/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:33:59 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 17:23:22 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **path, char **commands)
{
	char	*temp_path;
	char	*exec_path;
	int		i;

	i = 0;
	while (path[i])
	{
		temp_path = ft_strjoin(path[i], "/");
		exec_path = ft_strjoin(temp_path, *commands);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			ft_free_array(path);
			free(temp_path);
			return (exec_path);
		}
		free(temp_path);
		free(exec_path);
		i++;
	}
	ft_free_array(path);
	return (NULL);
}

char	*find_my_path(char **full_path)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	while (full_path[i] != NULL)
	{
		if (ft_strncmp(full_path[i], "PATH=", 5) == 0)
		{
			res = full_path[i] + 5;
			break ;
		}
		i++;
	}
	return (res);
}

void	check_args(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Too few arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc > 5)
	{
		ft_putstr_fd("Too many arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		i++;
	}
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
