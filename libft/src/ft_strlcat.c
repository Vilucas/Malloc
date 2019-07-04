/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:26:07 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/18 13:27:50 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			n;
	size_t			len;

	n = 0;
	i = 0;
	len = ft_strlen(dst) + ft_strlen((char*)src);
	while (dst[i])
		i++;
	while (src[n] && i < size - 1 && size > 0)
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
	if (ft_strlen(dst) > size)
		return (size + ft_strlen((char*)src));
	return (len);
}
