/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:42:06 by reerikai          #+#    #+#             */
/*   Updated: 2024/10/31 18:28:29 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t size)
{
	unsigned char	*temp_ptr;
	size_t			i;

	temp_ptr = ptr;
	i = 0;
	while (size > i)
	{
		temp_ptr[i] = c;
		i++;
	}
	return (ptr);
}
