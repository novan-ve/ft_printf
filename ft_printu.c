/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printu.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 17:30:51 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/24 20:54:15 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu2(t_print *p)
{
	int		i;

	i = 0;
	while (i < p->tmpwidth - p->tmplen && i < p->tmpwidth - p->prec && p->just == 'l')
	{
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
	if (p->prec != 0)
		ft_uputnbr_fd(p->itmp, 1);
	i = 0;
	while (i < p->tmpwidth - p->tmplen && i < p->tmpwidth - p->prec && p->just == 'r')
	{
		ft_putchar_fd(p->padchar, 1);
		i++;
	}
}

void	ft_printu(t_print *p)
{
	p->itmp = va_arg(p->args, unsigned int);
	p->tmplen += ft_nbrlenu(p->itmp, 1);
	if (p->prec == 0)
		p->tmplen = 0;
	if (p->tmplen < p->tmpwidth || p->prec != -1)
		ft_printu2(p);
	else
		ft_uputnbr_fd(p->itmp, 1);
}
