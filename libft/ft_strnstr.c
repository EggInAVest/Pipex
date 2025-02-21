/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:06:43 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/07 14:11:51 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	k;
	char	*res;

	i = 0;
	res = ((char *)str);
	if (str == NULL || to_find == NULL)
		return (NULL);
	if (to_find[0] == '\0')
		return (&res[i]);
	while (i < size && str[i] != '\0')
	{
		k = 0;
		while (str[i + k] == to_find[k] && (i + k) < size)
		{
			if (to_find[k + 1] == '\0')
				return (&res[i]);
			k++;
		}
		i++;
	}
	return (0);
}
