/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:07:02 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/05 17:38:51 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	char	*temp;
	size_t	i;

	temp = (char *)ptr;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
