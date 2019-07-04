/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 04:50:45 by viclucas          #+#    #+#             */
/*   Updated: 2019/06/27 05:34:40 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*small_realloc(t_block *tmpblock, size_t size)
{
	tmpblock->dust = tmpblock->size - size;
	tmpblock->size = size;
	return (tmpblock + sizeof(t_block));
}

void		*big_realloc(t_block *area, size_t size)
{
	void	*new;

	new = malloc(size);
	ft_strncpy(new, (char*)(area + sizeof(t_block)), size);
	free(area + sizeof(t_block));
	return (new);
}
