/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:24:14 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/10 14:23:38 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return ((char*)(s + i));
	}
	while (s[i])
	{
		if (s[i] == c)
			ret = (char*)&s[i];
		i++;
	}
	return (ret);
}
