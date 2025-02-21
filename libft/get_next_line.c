/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:41 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/23 15:52:46 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp_buffer;
	char		*found_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp_buffer == NULL)
		return (free(buffer), buffer = NULL, NULL);
	while (1)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp_buffer), free(buffer), buffer = NULL, NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin_nl(buffer, temp_buffer);
		if (find_nl(temp_buffer) || bytes_read == 0)
			break ;
	}
	if (bytes_read == 0 && buffer[0] == '\0')
		return (free(buffer), free(temp_buffer), buffer = NULL, NULL);
	found_line = extract_line(buffer);
	buffer = leftover(buffer);
	return (free(temp_buffer), found_line);
}

size_t	find_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *buffer)
{
	char	*new_line;
	int		i;
	int		len;

	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	new_line = malloc((len + 1) * sizeof(char));
	if (new_line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_line[i] = buffer[i];
		i++;
	}
	new_line[len] = '\0';
	return (new_line);
}

char	*leftover(char *buffer)
{
	char	*new_buffer;
	size_t	len;
	size_t	i;

	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	i = 0;
	new_buffer = malloc((ft_strlen_nl(buffer) - len + 1) * sizeof(char));
	if (new_buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[len] != '\0')
	{
		new_buffer[i] = buffer[len];
		i++;
		len++;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}
