/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:50:20 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/12 15:34:43 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		(*(unsigned char*)dst) = (*(unsigned char*)src);
		if (*(unsigned char*)src == (unsigned char)c)
			return ((unsigned char*)(dst) + 1);
		dst++;
		src++;
		i++;
	}
	return (NULL);
}
