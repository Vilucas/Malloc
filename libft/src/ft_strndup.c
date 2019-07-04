/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:47:21 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/10 12:20:57 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s1, int nb)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	if (!(p = (char*)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && i < nb)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
