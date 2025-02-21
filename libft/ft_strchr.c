/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:40:45 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/12 15:47:46 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search)
{
	while (*str != '\0')
	{
		if ((unsigned char)*str == ((unsigned char)search))
		{
			return ((char *)str);
		}
		str++;
	}
	if (search == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
