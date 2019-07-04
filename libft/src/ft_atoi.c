/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:54:00 by viclucas          #+#    #+#             */
/*   Updated: 2017/11/17 16:22:31 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			i;
	int			signe;
	int			result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	return (result * signe);
}
