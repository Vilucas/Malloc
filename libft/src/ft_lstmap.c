/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:34:15 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/18 19:26:09 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tab;

	if (!(tab = malloc(sizeof(tab))))
		return (NULL);
	if (lst)
	{
		tab = f(lst);
		tab->next = ft_lstmap(lst->next, f);
		return (tab);
	}
	return (NULL);
}
