/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:57:56 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/07 19:10:38 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int num);

static char	*ft_convert(char *str);

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	res = malloc((ft_count(n) + 1) * (sizeof(char)));
	if (res == NULL)
		return (NULL);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		n = -n;
	}
	while (n / 10 != 0)
	{
		res[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (n < 10)
		res[i++] = n + '0';
	res[i] = '\0';
	ft_convert(res);
	return (res);
}

static int	ft_count(int num)
{
	int	counter;

	counter = 0;
	if (num < 0)
	{
		counter++;
	}
	while (num / 10 != 0)
	{
		num = num / 10;
		counter++;
	}
	counter++;
	return (counter);
}

static char	*ft_convert(char *str)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str) - 1;
	if (str[start] == '-')
		start++;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
	return (str);
}
