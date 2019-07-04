/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:49:34 by viclucas          #+#    #+#             */
/*   Updated: 2019/07/01 16:39:25 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M (1024 * 1024)
#include "malloc.h"

void			*get_addr_block(void *addr, t_block *lst, size_t size)
{
	t_block	*tmp;
	int		pow;

	tmp = lst;
	pow = 0;
	if (!(tmp))
		return (NULL);
	while (tmp)
	{
		if (tmp->used == 0 && tmp->size >= size)
			return (addr + sizeof(t_block));
		addr = addr + sizeof(t_block) + tmp->size + tmp->dust;
		tmp = tmp->next;
	}
	return (addr);
}

t_block			*stock_in(size_t size, int pow)
{
	t_page		*tmp;
	t_block		*ret;
	t_block		*tmp_block;

	tmp = g_var;
	while (pow > 0)
	{
		tmp = tmp->next;
		pow--;
	}
	tmp_block = tmp->first;
	ret = packing_block(get_addr_block(tmp + sizeof(t_page), tmp->first, size),
			size, tmp->first);
	while (tmp_block)
		tmp_block = tmp_block->next;
	tmp_block = ret;
	tmp_block->next = NULL;
	return (tmp_block + sizeof(t_block));
}

t_block			*allocating_new_page(size_t size)
{
	t_page		*new;
	size_t		len;
	t_page		*tmp;

	tmp = g_var;
	len = size_page(size_type(size), size);
	if (!(new = mmap(NULL, len, PROT_READ | PROT_WRITE,
					MAP_SHARED | MAP_ANON, -1, 0)))
		return (NULL);
	new->type = size_type(size);
	new->first = packing_block(new + sizeof(t_page), size, NULL);
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		g_var = new;
	return (new->first + sizeof(t_block));
}

void			*malloc(size_t size)
{
	t_page		*new;
	int			pow;

	pow = 0;
	new = NULL;
	if (first_check(size, &pow) == -1)
		return (allocating_new_page(size));
	return (stock_in(size, pow));
}
