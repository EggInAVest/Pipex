/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:50:18 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/30 16:10:12 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		len;
	int		res;

	va_start(arguments, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format++;
			res = sort_arg(arguments, format[i]);
			if (res == -1)
				return (-1);
			len = len + res;
			format++;
		}
		else
			if (ft_printchar(format[i++]) == -1)
				return (-1);
	}
	va_end(arguments);
	return (len + i);
}

int	sort_arg(va_list arguments, const char c)
{
	int	count;

	if (c == 'c')
		count = ft_printchar(va_arg(arguments, int));
	else if (c == 's')
		count = ft_printstr(va_arg(arguments, char *));
	else if (c == 'p')
		count = ft_printptr((unsigned long)(va_arg(arguments, void *)));
	else if (c == 'd' || c == 'i')
		count = ft_printnbr(va_arg(arguments, int));
	else if (c == 'u')
		count = ft_un_printnbr(va_arg(arguments, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_printhex(va_arg(arguments, unsigned int), c);
	else if (c == '%')
		count = ft_printchar('%');
	else
	{
		count = ft_printchar('%');
		count = count + ft_printchar(c);
	}
	if (count == -1)
		return (-1);
	return (count);
}
