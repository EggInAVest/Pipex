/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:52:20 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/07 11:59:33 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	k;
	size_t	dest_len;
	size_t	src_len;

	if (src == NULL)
		return (0);
	src_len = ft_strlen(src);
	if (dest == NULL && destsize == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dest_len >= destsize)
		return (destsize + src_len);
	i = dest_len;
	k = 0;
	while (src[k] != '\0' && i + 1 < destsize)
	{
		dest[i] = src[k];
		i++;
		k++;
	}	
	dest[i] = '\0';
	return (src_len + dest_len);
}
