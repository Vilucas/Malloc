/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:52:27 by viclucas          #+#    #+#             */
/*   Updated: 2018/07/04 15:35:37 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int result;

	i = 0;
	while (s1[i] == s2[i] && s2[i])
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
