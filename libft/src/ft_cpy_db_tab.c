/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_db_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:48:04 by viclucas          #+#    #+#             */
/*   Updated: 2018/04/03 15:40:05 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_cpy_db_tab(char **env)
{
	char	**ret;
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (env[i])
		i++;
	if (!(ret = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (env[i])
		ret[o++] = ft_strdup(env[i++]);
	ret[o] = 0;
	return (ret);
}
