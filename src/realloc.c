/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:09:07 by viclucas          #+#    #+#             */
/*   Updated: 2019/06/27 05:34:30 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block		*browse_blocks(t_block *tmblock, size_t size, void *ptr, int *token)
{
	while (tmblock)
	{
		if (tmblock + sizeof(t_block) == ptr)
		{
			if (tmblock->size > size)
			{
				*token = 1;
				return (tmblock);
			}
			*token = -2;
			return (tmblock);
		}
		tmblock = tmblock->next;
	}
	return (0);
}

t_block		*first_infos(void *ptr, size_t size, int *token)
{
	t_page		*tmp;
	t_block		*tmblock;
	t_block		*ret;

	if (!(tmp = g_var))
	{
		*token = -1;
		return (NULL);
	}
	while (tmp)
	{
		tmblock = tmp->first;
		if ((ret = browse_blocks(tmblock, size, ptr, token)) != 0)
			return (ret);
		tmp = tmp->next;
	}
	*token = -1;
	return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
	int			token;
	t_block		*working_area;
	void		*ret;

	if (ptr == 0)
		return ((ret = malloc(size)));
	if (!g_var)
		return (NULL);
	if (!(working_area = first_infos(ptr, size, &token)))
		return (NULL);
	if (token == -1)
		return (NULL);
	else if (token == 1)
		return (ret = small_realloc(working_area, size));
	else if (token == -2)
		return (ret = big_realloc(working_area, size));
	return (NULL);
}
