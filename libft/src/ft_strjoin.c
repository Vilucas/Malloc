/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:11:43 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/02 18:10:30 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		o;
	char	*p;

	o = 0;
	i = 0;
	if (!(s1) || (!(s2)))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[o])
		o++;
	if (!(p = (char*)malloc(sizeof(*p) * (i + o) + 1)))
		return (NULL);
	i = 0;
	o = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[o])
		p[i++] = s2[o++];
	p[i] = '\0';
	return (p);
}
