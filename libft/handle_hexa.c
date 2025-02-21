/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:11:35 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/29 12:02:23 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_count(unsigned long nb)
{
	int	counter;

	counter = 0;
	while (nb / 16 != 0)
	{
		nb = nb / 16;
		counter++;
	}
	counter++;
	return (counter);
}

int	ft_printhex(unsigned long nb, const char c)
{
	int	count;

	count = ft_hex_count(nb);
	if (nb / 16 != 0)
	{
		if (ft_printhex(nb / 16, c) == -1)
			return (-1);
	}
	if (nb % 16 >= 10 && nb % 16 <= 15)
	{
		if (c == 'X')
		{
			if (ft_printchar(nb % 16 + 55) == -1)
				return (-1);
		}
		else if (c == 'x')
			if (ft_printchar(nb % 16 + 87) == -1)
				return (-1);
	}
	if (nb % 16 < 10)
	{
		if (ft_printchar(nb % 16 + '0') == -1)
			return (-1);
	}
	return (count);
}

int	ft_printptr(unsigned long ptr)
{
	int	count;
	int	hexcount;

	if (!ptr)
		return (ft_printstr("(nil)"));
	count = ft_printstr("0x");
	if (count == -1)
		return (-1);
	hexcount = ft_printhex(ptr, 'x');
	if (hexcount == -1)
		return (-1);
	return (hexcount + count);
}
