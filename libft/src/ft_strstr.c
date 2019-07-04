/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:27:29 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/13 17:30:45 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(needle[0]))
		return ((char*)(haystack));
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)(haystack + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
