/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:39:00 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/12 15:53:54 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search)
{
	const char	*found;

	found = 0;
	while (*str != '\0')
	{
		if ((unsigned char)*str == (unsigned char)search)
		{
			found = str;
		}
		str++;
	}
	if (search == '\0')
	{
		return ((char *)str);
	}
	return ((char *)found);
}
