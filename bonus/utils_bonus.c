/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:48:35 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 17:15:08 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	open_file(char *file, int code)
{
	int	res;

	res = 0;
	if (code == 0)
		res = open(file, O_RDONLY);
	else if (code == 1)
		res = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (code == 2)
		res = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (res == -1)
		perror_and_exit(file);
	return (res);
}
