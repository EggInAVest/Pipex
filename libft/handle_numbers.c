/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:39:40 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/29 12:24:31 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_un_count(unsigned int nb)
{
	int	counter;

	counter = 0;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		counter++;
	}
	counter++;
	return (counter);
}

int	ft_pcount(int nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
		counter++;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		counter++;
	}
	counter++;
	return (counter);
}

int	ft_printnbr(int nb)
{
	int	count;

	count = ft_pcount(nb);
	if (nb == -2147483648)
	{
		if (ft_printstr("-2147483648") == -1)
			return (-1);
		return (11);
	}
	else if (nb < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		ft_printnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_printnbr(nb / 10);
		if (ft_printchar(nb % 10 + '0') == -1)
			return (-1);
	}
	else
		if (ft_printchar(nb + '0') == -1)
			return (-1);
	return (count);
}

int	ft_un_printnbr(unsigned int nb)
{
	int	count;

	count = ft_un_count(nb);
	if (nb > 9)
	{
		ft_un_printnbr(nb / 10);
		if (ft_printchar(nb % 10 + '0') == -1)
			return (-1);
	}
	else
		if (ft_printchar(nb + '0') == -1)
			return (-1);
	return (count);
}
