/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:14:20 by viclucas          #+#    #+#             */
/*   Updated: 2018/01/11 20:14:54 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_suply(const char *s, int *i, va_list *ap)
{
	t_printf x;

	ft_bzero(&x, sizeof(t_printf));
	if (s[*i + 1] == 's')
	{
		x.tmp = va_arg(*ap, char *);
		ft_putstr(x.tmp);
		*i = *i + 2;
	}
	else if (s[*i + 1] == 'd')
	{
		x.o = va_arg(*ap, int);
		ft_putnbr(x.o);
		*i = *i + 2;
	}
}

void		ft_printf(const char *s, ...)
{
	t_printf	x;
	va_list		ap;

	va_start(ap, s);
	ft_bzero(&x, sizeof(t_printf));
	while (s[x.i])
	{
		if (s[x.i] == '%')
		{
			ft_suply(s, &x.i, &ap);
		}
		else
		{
			ft_putchar(s[x.i]);
			x.i++;
		}
	}
	va_end(ap);
}
