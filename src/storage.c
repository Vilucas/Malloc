/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:13:10 by viclucas          #+#    #+#             */
/*   Updated: 2019/06/27 05:41:39 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	*run_down_global(void *address)
{
	t_page *tmp;

	if (!(tmp = g_var))
		return (NULL);
	while (tmp)
	{
		while (tmp->first)
		{
			if (tmp->first + sizeof(t_block) == address)
				return (tmp->first);
			tmp->first = tmp->first->next;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_block	*dusty(size_t size, t_block *tmp)
{
	tmp->dust += tmp->size - size;
	tmp->size = size;
	tmp->used = 1;
	return (tmp);
}

t_block	*new_page_storage(void *address, size_t size)
{
	t_block *new;

	new = (t_block*)address;
	new->size = size;
	new->used = 1;
	new->next = NULL;
	new->dust = 0;
	return (new);
}

t_block	*packing_block(void *address, size_t size, t_block *lst)
{
	t_block	*new;
	t_block	*tmp;

	if (!(tmp = lst))
		return (new_page_storage(address, size));
	while (tmp)
	{
		if (tmp->used == 0 && tmp->size >= size)
			return (dusty(size, tmp));
		if (!(tmp->next))
			break ;
		tmp = tmp->next;
	}
	new = (t_block*)address;
	tmp->next = new;
	new->size = size;
	new->used = 1;
	new->next = NULL;
	new->dust = 0;
	lst = tmp;
	return (new);
}
