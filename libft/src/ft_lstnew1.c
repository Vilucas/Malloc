/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:10:03 by viclucas          #+#    #+#             */
/*   Updated: 2018/04/05 18:16:21 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_file	*ft_lstnew1(char *content, t_file *list, int flag)
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
