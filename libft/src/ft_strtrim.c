/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:16:18 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/16 14:25:29 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static int		ft_does_count(char const *s)
{
	int		i;
	char	result;

	i = 0;
	result = 0;
	while (ft_is_blank(s[i]) == 1)
	{
		if (s[i + 1] == '\0')
			return (0);
		i++;
	}
	while (s[i])
	{
		i++;
		result++;
	}
	i--;
	while (ft_is_blank(s[i]) == 1)
	{
		result--;
		i--;
	}
	return (result);
}

char			*ft_strtrim(char const *s)
{
	char	*p;
	int		i;
	int		o;
	int		u;

	u = 0;
	i = 0;
	if (!(s))
		return (NULL);
	o = ft_does_count(s);
	if (!(p = (char*)malloc(sizeof(*p) * o + 1)))
		return (NULL);
	while (ft_is_blank(s[u]) == 1)
		u++;
	while (o)
	{
		p[i] = s[u];
		i++;
		u++;
		o--;
	}
	p[i] = '\0';
	return (p);
}
