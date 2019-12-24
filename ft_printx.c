/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 17:05:03 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/24 20:57:03 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printx2(t_print *p)
{
	int		i;

	i = 0;
	while (i < p->tmpwidth - p->tmplen && i < p->tmpwidth - p->prec && p->just == 'l')
	{
		p->len++;
		ft_putchar_fd(p->padchar, 1);
		i++;
	}
	i = 0;
	while (i < (p->prec - p->tmplen))
	{
		p->len++;
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putstr_fd(p->hex, 1);
	i = 0;
	while (i < p->tmpwidth - p->tmplen && i < p->tmpwidth - p->prec && p->just == 'r')
	{
		p->len++;
		ft_putchar_fd(p->padchar, 1);
		i++;
	}
}

void	ft_printx(t_print *p, int x)
{
	ft_dec_to_hex(p, va_arg(p->args, unsigned long), x, 16);
	if (p->hex[0] == '\0' && p->prec != 0)
	{
		p->hex[0] = '0';
		p->tmplen = 1;
	}
	if (p->tmplen < p->tmpwidth || p->prec != -1)
		ft_printx2(p);
	else
		ft_putstr_fd(p->hex, 1);
}
