/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:50 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/23 15:27:00 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_nl(const char *str)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc((ft_strlen_nl(str) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_nl(char *str1, char *str2)
{
	char	*ptr;
	int		i;
	int		k;
	int		j;
	int		tot_len;

	if (!str1)
		str1 = ft_strdup_nl("");
	if (!str2)
		str2 = ft_strdup_nl("");
	tot_len = ft_strlen_nl(str1) + ft_strlen_nl(str2);
	ptr = malloc((tot_len + 1) * sizeof(char));
	if (!ptr)
		return (free(str1), NULL);
	i = 0;
	k = 0;
	while (str1[k] != '\0')
		ptr[i++] = str1[k++];
	j = 0;
	while (str2[j] != '\0')
		ptr[i++] = str2[j++];
	ptr[i] = '\0';
	free(str1);
	return (ptr);
}

size_t	ft_strlen_nl(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] != '\0')
		len++;
	return (len);
}
