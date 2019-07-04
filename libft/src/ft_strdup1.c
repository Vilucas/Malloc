/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:47:21 by viclucas          #+#    #+#             */
/*   Updated: 2018/07/11 18:01:59 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "unistd.h"

char	*ft_strdup1(const char *s1)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	if (!(p = (char*)malloc(sizeof(*p) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
