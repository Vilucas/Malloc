/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:45:29 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/18 19:25:07 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		ft_words(char const *s, char c)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i + 1] == c && s[i] != c) || (s[i + 1] == '\0' && s[i] != c))
			result++;
		i++;
	}
	return (result);
}

static int		ft_strlen2(char const *s, char c)
{
	int i;
	int lenght;

	lenght = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		*ft_strcpy2(char *s1, char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static char		*ft_allocate2(char const *s, char c)
{
	char	*p;
	int		lenght;

	p = NULL;
	lenght = ft_strlen2(s, c);
	if (!(p = (char*)malloc(sizeof(p) * lenght + 1)))
		return (NULL);
	return (ft_strcpy2(p, s, c));
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**p;
	int		words;
	int		o;

	o = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	words = ft_words(s, c);
	if (!(p = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (o < words)
	{
		if (s[i] != c)
		{
			p[o++] = ft_allocate2((s + i), c);
			i = i + ft_strlen2((s + i), c);
		}
		else
			i++;
	}
	p[o] = 0;
	return (p);
}
