/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:13:37 by viclucas          #+#    #+#             */
/*   Updated: 2018/07/12 21:04:09 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_stdup(char *s, int flag)
{
	t_stock r;

	ft_bzero(&r, sizeof(t_stock));
	while (s[r.i] && s[r.i] != '\n')
		r.i++;
	if (flag == 1)
	{
		r.save = ft_strsub(s, 0, r.i);
		return (r.save);
	}
	return (NULL);
}

char	*ft_realloc(char *s)
{
	int			i;
	int			o;
	char		*ret;

	o = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	while (s[i])
	{
		i++;
		o++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * (o + 1))))
		return (NULL);
	i = i - o;
	o = 0;
	while (s[i])
		ret[o++] = s[i++];
	ret[o] = '\0';
	return (ret);
}

int		suply_fonction(t_stock r, char **line, char **tmp)
{
	if (r.ret == -1)
		return (-1);
	if (*tmp)
	{
		if (r.total == 0 && *tmp[0] != '\0')
		{
			r.tmp_swap = *tmp;
			*line = ft_strdup(*tmp);
			*tmp = ft_realloc(*tmp);
			ft_strdel(&r.tmp_swap);
			return (1);
		}
	}
	if (r.total != 0)
	{
		*line = ft_strdup(r.result);
		ft_strdel(tmp);
		*tmp = ft_realloc(r.p);
		ft_strdel(&r.result);
		free(r.save);
		return (1);
	}
	*line = NULL;
	return (0);
}

int		ft_loop(t_stock *r, char **tmp)
{
	r->total += r->ret;
	r->p[r->ret] = '\0';
	r->save = ft_stdup(r->p, 1);
	ft_strdel(&r->result);
	if (*tmp)
		r->result = ft_strjoin(*tmp, r->save);
	else
		r->result = ft_strdup(r->save);
	ft_strdel(&r->save);
	ft_strdel(tmp);
	if (ft_strchr(r->p, '\n'))
		return (1);
	*tmp = ft_strdup(r->result);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	t_stock		r;
	static char	*tmp;

	ft_bzero(&r, sizeof(t_stock));
	if (!line || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (tmp && ft_strchr(tmp, '\n'))
	{
		r.tmp_swap = tmp;
		*line = ft_stdup(tmp, 1);
		tmp = ft_realloc(tmp);
		ft_strdel(&r.tmp_swap);
		return (1);
	}
	while ((r.ret = read(fd, r.p, BUFF_SIZE)) > 0)
	{
		if (ft_loop(&r, &tmp) == 1)
			break ;
	}
	return (suply_fonction(r, line, &tmp));
}
