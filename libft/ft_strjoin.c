/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:49:33 by reerikai          #+#    #+#             */
/*   Updated: 2025/01/23 15:29:35 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*ptr;
	int		i;
	int		k;
	int		j;
	int		tot_len;

	tot_len = ft_strlen(str1) + ft_strlen(str2);
	ptr = malloc((tot_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str1[k] != '\0')
		ptr[i++] = str1[k++];
	j = 0;
	while (str2[j] != '\0')
	{
		ptr[i] = str2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
