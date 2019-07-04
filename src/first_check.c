/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 05:32:53 by viclucas          #+#    #+#             */
/*   Updated: 2019/06/27 05:33:15 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	size_page(int type, size_t size)
{
	size_t	page_size;

	page_size = (type == 1) ? TINY_PAGE : SMALL_PAGE;
	if (type == 3)
	{
		page_size = 0;
		while (page_size < (size + sizeof(t_page) + sizeof(t_block)))
			page_size += 4096;
		page_size += 4096;
	}
	return (page_size);
}

int		size_type(size_t size)
{
	if (size <= TINY)
		return (1);
	if (size <= SMALL)
		return (2);
	return (3);
}

int		space_remaining(t_page *ptr, int size)
{
	t_block		*block;
	size_t		page_size;
	size_t		count;

	count = 0;
	page_size = (ptr->type == 1) ? TINY_PAGE : SMALL_PAGE;
	block = ptr->first;
	while (block)
	{
		count = count + block->size + block->dust + sizeof(t_block);
		block = block->next;
	}
	if ((page_size - count) - (size + sizeof(t_block)) > 1120 + sizeof(t_block))
		return (0);
	return (-1);
}

int		place_available(size_t size, int *pow)
{
	t_page		*ptr;
	int			ref_size;

	ref_size = size_type(size);
	ptr = g_var;
	while (ptr)
	{
		if (ref_size == ptr->type && space_remaining(ptr, size) == 0)
			return (0);
		*pow = *pow + 1;
		ptr = ptr->next;
	}
	return (-1);
}

int		first_check(size_t size, int *pow)
{
	if (!g_var || size > 1024)
		return (-1);
	if (place_available(size, pow) == -1)
		return (-1);
	return (0);
}
