/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:18:56 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/17 21:38:02 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (*(unsigned char*)s1) == (*(unsigned char*)s2))
	{
		s1++;
		s2++;
		i++;
	}
	return ((*(unsigned char*)s1) - (*(unsigned char*)s2));
}
