/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:03:16 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/15 16:04:12 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[i] = str[i] - 32;
	i++;
	while (str[i])
	{
		if ((str[i - 1] < 'A' || str[i - 1] > 'Z') &&
				(str[i - 1] < 'a' || str[i - 1] > 'z') &&
				(str[i - 1] < '0' || str[i - 1] > '9'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
