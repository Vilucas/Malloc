/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:06:03 by viclucas          #+#    #+#             */
/*   Updated: 2019/06/25 02:36:40 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		print_page_hexa(int type, void *addr)
{
	if (type == 1)
		ft_putstr("TINY : ");
	else if (type == 2)
		ft_putstr("SMALL : ");
	else if (type == 3)
		ft_putstr("LARGE : ");
	ft_putstr(" 0x");
	hexa_for((size_t)addr);
	ft_putchar('\n');
}

static void		print_block_hexa(void *addr, size_t size)
{
	ft_putstr("0x");
	hexa_for((size_t)addr);
	ft_putstr(" - 0x");
	hexa_for((size_t)addr + size);
	ft_putstr(" : ");
	ft_putnbr_size_t(size);
	ft_putendl(" octets");
}

static size_t	print_content_hexa(t_page *tmp)
{
	size_t			count;
	t_block			*tmp_block;

	count = 0;
	print_page_hexa(tmp->type, tmp + sizeof(t_page));
	tmp_block = tmp->first;
	while (tmp_block)
	{
		ft_putchar(' ');
		print_block_hexa(tmp_block + sizeof(t_block), tmp_block->size);
		count += tmp_block->size;
		tmp_block = tmp_block->next;
	}
	return (count);
}

void			show_alloc_mem_lib(void)
{
	t_page			*tmp;
	int				var;
	size_t			total;

	total = 0;
	var = 0;
	if (!(tmp = g_var))
		return ;
	while (var < 4)
	{
		while (tmp)
		{
			if (tmp->type == var)
				total += print_content_hexa(tmp);
			tmp = tmp->next;
		}
		var++;
		tmp = g_var;
	}
	ft_putstr("Total : ");
	ft_putnbr_size_t(total);
	ft_putendl(" octets");
}
