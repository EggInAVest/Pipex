/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:40 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/11 11:53:59 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	len = ft_strlen(str);
	res = malloc((len + 1) * (sizeof(char)));
	if (res == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		res[i] = (*f)(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
