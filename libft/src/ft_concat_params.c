/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:50:47 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/15 16:24:22 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_allocate_tab(int argc, char **argv, char *p)
{
	int i;
	int j;
	int r;

	j = 1;
	r = 0;
	i = 0;
	while (j < argc)
	{
		while (argv[j][i])
		{
			p[r] = argv[j][i];
			r++;
			i++;
		}
		i = 0;
		j++;
		if (j != argc)
			p[r++] = '\n';
	}
	p[r] = '\0';
	return (p);
}

static int		ft_get_lenght(int argc, char **argv)
{
	int i;
	int r;
	int j;
	int len;

	len = 0;
	j = 1;
	r = 0;
	i = 0;
	while (i < argc - 1)
	{
		while (argv[j][r])
		{
			r++;
		}
		r++;
		len = len + r;
		j++;
		r = 0;
		i++;
	}
	return (len);
}

char			*ft_concat_params(int argc, char **argv)
{
	int		len;
	char	*p;

	len = ft_get_lenght(argc, argv);
	if (!(p = (char*)malloc(sizeof(p) * len + 1)))
		return (0);
	p = ft_allocate_tab(argc, argv, p);
	return (p);
}
