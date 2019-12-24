/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printxp.c		                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 17:24:38 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/24 21:24:54 by anon          ########   odam.nl         */
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

void	ft_printp2(t_print *p)
{
	int		i;

	i = 0;
	if (p->just == 'r' || p->padchar == '0')
		ft_putstr_fd("0x", 1);
	if (p->just == 'r')
		ft_putstr_fd(p->hex, 1);
	while (i < (p->tmpwidth - p->tmplen))
	{
		ft_putchar_fd(p->padchar, 1);
		i++;
	}
	i = 0;
	if (p->just == 'l' && p->padchar != '0')
		ft_putstr_fd("0x", 1);
	while (i < (p->prec - p->tmplen + 2))
	{
		p->len++;
		ft_putchar_fd('0', 1);
		i++;
	}
	if (p->just == 'l')
		ft_putstr_fd(p->hex, 1);
}

void	ft_printp(t_print *p)
{
	ft_dec_to_hex(p, va_arg(p->args, unsigned long), 0, 13);
	p->tmplen += 2;
	if (p->hex[0] == '\0')
	{
		p->tmplen = 5;
		ft_putstr_fd("(nil)", 1);
	}
	else
		ft_printp2(p);
}
