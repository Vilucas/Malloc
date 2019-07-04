/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pack_ex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:22 by viclucas          #+#    #+#             */
/*   Updated: 2018/03/24 21:12:41 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_file		*ft_lstnew1(char *content, t_file *list, int flag)
{
	t_file *k;

	if (!(k = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	k->content = NULL;
	if (content && flag == 1)
		k->content = ft_strdup(content);
	else if (content && flag == 0)
		k->content = content;
	k->cont = NULL;
	k->next = NULL;
	ft_bzero(&k->data, sizeof(t_data));
	if (list)
		k->next = list;
	return (k);
}

t_slist		*ft_lstnew2(t_data data, t_slist *list, int flag)
{
	t_slist *new;

	if (!(new = (t_slist*)malloc(sizeof(t_slist))))
		return (NULL);
	ft_bzero(new, sizeof(t_slist));
	if (data.content == NULL)
		new->data.content = NULL;
	else if (data.content && flag == 0)
		new->data.content = data.content;
	else if (data.content && flag == 1)
		new->data.content = ft_strdup(data.content);
	if (data.modif == 0)
		new->data.modif = 0;
	else if (data.modif != 0)
		new->data.modif = data.modif;
	new->next = NULL;
	if (list)
		new->next = list;
	return (new);
}

t_file		*ft_delete_list(t_file *keep)
{
	t_file	*tmp2;
	t_slist *tmpnxt;
	t_slist *tmp;

	tmp = NULL;
	if (keep->cont)
		tmp = keep->cont;
	tmp2 = keep;
	if (tmp)
	{
		while (tmp)
		{
			tmpnxt = tmp->next;
			ft_strdel(&tmp->data.content);
			free(tmp);
			tmp = NULL;
			tmp = tmpnxt;
		}
	}
	ft_strdel(&tmp2->content);
	free(tmp2);
	return (NULL);
}

t_file		*ft_debut_delete_list(t_file *p)
{
	t_file *tmp;

	tmp = p;
	if (p == NULL)
	{
		return (NULL);
	}
	tmp = p->next;
	free(p);
	return (tmp);
}
