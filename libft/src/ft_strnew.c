/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:41:07 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/15 13:02:38 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*p;
	size_t		i;

	i = 0;
	if (!(p = (char*)malloc(sizeof(*p) * size + 1)))
		return (NULL);
	while (i < size)
	{
		p[i] = '\0';
		i++;
	}
	p[i] = '\0';
	return (p);
}
