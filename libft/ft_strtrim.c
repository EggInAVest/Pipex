/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:11:36 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/06 15:58:32 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sortset(char const *set, char c);

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		k;
	int		str_len;
	char	*ptr;

	str_len = ft_strlen(str) - 1;
	i = 0;
	while (ft_sortset(set, str[i]))
		i++;
	while (ft_sortset(set, str[str_len]) && str_len > i)
		str_len--;
	ptr = malloc((str_len - i + 2) * (sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	k = 0;
	while (str_len >= i)
	{
		ptr[k] = str[i];
		k++;
		i++;
	}
	ptr[k] = '\0';
	return (ptr);
}

static int	ft_sortset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
