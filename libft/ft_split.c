/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:25:00 by reerikai          #+#    #+#             */
/*   Updated: 2024/11/12 18:51:01 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_splat(char const *str, char c, char **res, int k);

static int	ft_countdel(char const *str, char c);

static char	*ft_fillstr(char const *str, char c, int start, int end);

static void	*ft_free(char **array, int i);

char	**ft_split(char const *str, char c)
{
	char	**res;

	if (str == NULL)
		return (NULL);
	res = malloc((ft_countdel(str, c) + 1) * (sizeof(char *)));
	if (res == NULL)
		return (NULL);
	ft_splat(str, c, res, 0);
	return (res);
}

static void	ft_splat(char const *str, char c, char **res, int k)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		start = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (start < i)
		{
			res[k] = ft_fillstr(str, c, start, i);
			if (res[k] == NULL)
			{
				ft_free(res, k);
				return ;
			}
			k++;
		}
	}
	res[k] = 0;
}

static int	ft_countdel(char const *str, char c)
{
	size_t	counter;
	int		i;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			counter++;
		}
		else
			i++;
	}
	return (counter);
}

static char	*ft_fillstr(char const *str, char c, int start, int end)
{
	int		i;
	char	*res;

	res = malloc((end - start + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start < end && str[start] != c)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

static void	*ft_free(char **array, int i)
{
	while (i > 0)
	{
		free(array[i - 1]);
		i--;
	}
	free(array);
	return (NULL);
}
