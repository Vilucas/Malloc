/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 07:37:40 by viclucas          #+#    #+#             */
/*   Updated: 2018/07/07 02:10:04 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 400
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stock
{
	char		p[BUFF_SIZE + 1];
	char		*save;
	int			ret;
	int			total;
	char		*tmp_swap;
	char		*result;
	int			o;
	int			i;
}				t_stock;

int				get_next_line(const int fd, char **line);

#endif
