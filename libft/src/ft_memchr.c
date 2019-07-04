/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:05:29 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/17 15:01:54 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*(unsigned char*)s) == d)
			return ((char*)(s));
		s++;
		i++;
	}
	return (NULL);
}
