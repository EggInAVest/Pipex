/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_letters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:22:59 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/29 12:11:53 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;
	int	res;

	if (!str)
		return (i = ft_printstr("(null)"));
	i = 0;
	while (str[i] != '\0')
	{
		res = ft_printchar(str[i]);
		if (res == -1)
			return (-1);
		i++;
	}
	return (i);
}
