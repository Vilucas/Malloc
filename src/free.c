/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:56:14 by viclucas          #+#    #+#             */
/*   Updated: 2019/07/01 16:51:58 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <string.h>

void			ft_reattach(int i, t_page *cursor)
{
	t_page	*ptr;
	t_page	*prev;
	int		y;

	y = i - 1;
	prev = g_var;
	ptr = g_var;
	if (i == 0)
	{
		g_var = cursor->next;
		return ;
	}
	while (i--)
		ptr = ptr->next;
	while (y--)
		prev = prev->next;
	prev->next = cursor->next;
}

void			free_this_thing(t_block *tmp, t_page *cursor, int i)
{
	tmp->used = 0;
	if (cursor->type == 1 || cursor->type == 2)
		return ;
	else if (cursor->type == 3)
	{
		ft_reattach(i, cursor);
		if (munmap(cursor, size_page(3, cursor->first->size)) == -1)
			return ;
	}
}

void			free(void *ptr)
{
	t_page		*cursor;
	t_block		*tmp;
	int			i;

	i = 0;
	cursor = g_var;
	while (cursor)
	{
		tmp = cursor->first;
		while (tmp)
		{
			if (tmp + sizeof(t_block) == ptr)
			{
				free_this_thing(tmp, cursor, i);
				return ;
			}
			tmp = tmp->next;
		}
		i++;
		cursor = cursor->next;
	}
}
