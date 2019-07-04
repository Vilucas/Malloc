/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:02:29 by viclucas          #+#    #+#             */
/*   Updated: 2019/06/25 03:11:34 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>

# define TINY	64
# define SMALL	1024

# define TINY_PAGE  (3 * 4096)
# define SMALL_PAGE (27 * 4096)

typedef struct		s_page
{
	struct s_page	*next;
	int				type;
	struct s_block	*first;
	size_t			remain;
}					t_page;

typedef struct		s_block
{
	size_t			size;
	int				used;
	struct s_block	*next;
}					t_block;

t_page *g_var;

int					first_infos(void *ptr, size_t size);
void				*malloc(size_t size);
void				hexa_for(int nb);
void				print_lst();
void				show_alloc_mem(void);
int					first_check(t_page *new, size_t size, int *pow);
t_block				*packing_block(void *address, size_t size, t_block *lst);
int					size_type(size_t size);
size_t				size_page(int type, size_t size);

#endif
