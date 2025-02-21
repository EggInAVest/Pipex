/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:47:55 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/05 18:26:59 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*mdest;
	char	*msrc;
	size_t	i;

	mdest = (char *)dest;
	msrc = (char *)src;
	i = 0;
	if (size == 0 || mdest == msrc)
		return (dest);
	while (size > i)
	{
		if (mdest < msrc)
		{
			mdest[i] = msrc[i];
			i++;
		}
		else if (mdest > msrc)
		{
			mdest[size - 1] = msrc[size - 1];
			size--;
		}
	}
	return (dest);
}
