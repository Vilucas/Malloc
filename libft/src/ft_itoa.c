/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:48:49 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/15 16:24:42 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_neg(int n)
{
	n = -n;
	return (n);
}

static char		*ft_allocate(int n, char *p, int i, int signe)
{
	p[i] = '\0';
	while (i--)
	{
		p[i] = n % 10 + 48;
		n = n / 10;
	}
	if (signe == -1)
		p[0] = '-';
	return (p);
}

char			*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*p;
	int		signe;

	signe = 1;
	i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = ft_neg(n);
		i++;
		signe = -1;
	}
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	if (!(p = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (ft_allocate(n, p, i, signe));
}
