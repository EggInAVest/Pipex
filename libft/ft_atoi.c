/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:46:54 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/06 09:29:53 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	long	result;
	int		i;
	int		counter;

	i = 0;
	counter = 1;
	result = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i++] == '-')
			counter = -1;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + (ptr[i++] - '0');
		if (result < 0 && counter == 1)
			return (-1);
		if (result < 0 && counter == -1)
			return (0);
	}
	return ((int)(counter * result));
}
