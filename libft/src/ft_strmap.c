/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:38:04 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/16 14:25:08 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*p;

	i = 0;
	if (!(s))
		return (NULL);
	while (s[i])
		i++;
	if (!(p = (char*)malloc(sizeof(*p) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = f(s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
