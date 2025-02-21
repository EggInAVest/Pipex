/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:13:11 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 17:37:40 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
