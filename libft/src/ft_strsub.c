/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:45:46 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/16 14:22:22 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(p = (char*)malloc(sizeof(*p) * len + 1)))
		return (NULL);
	len = len + start;
	while (start < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
