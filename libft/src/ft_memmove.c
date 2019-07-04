/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:13:14 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/18 13:14:27 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*srcc;

	dest = (char*)dst;
	srcc = (char*)src;
	if (srcc < dest)
	{
		while (len)
		{
			len--;
			dest[len] = srcc[len];
		}
	}
	else
		ft_memcpy(dest, srcc, len);
	return (dest);
}
