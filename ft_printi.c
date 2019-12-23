/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 17:16:01 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/23 23:52:26 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printi(t_print *p)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	p->itmp = va_arg(p->args, int);
	p->tmplen += ft_nbrleni(p->itmp, 0);
	if (p->tmplen < p->tmpwidth || p->prec != -1)
	{
		i = 0;
		if (p->prec == 0)
		{
			p->tmplen = 0;
			k = 1;
		}
		if (p->prec == -1)
			p->prec = 0;
		if (p->itmp < 0)
		{
			if (p->padchar == '0')
				ft_putchar_fd('-', 1);
			p->tmplen--;
			p->itmp = -p->itmp;
			p->len++;
			p->tmpwidth--;
			j = 1;
		}
		while (i < p->tmpwidth - p->tmplen && i < p->tmpwidth - p->prec && p->just == 'l')
		{
			p->len++;
			ft_putchar_fd(p->padchar, 1);
			i++;
		}
		if (j == 1 && p->padchar != '0')
			ft_putchar_fd('-', 1);
		i = 0;
		while (i < (p->prec - p->tmplen))
		{
			p->len++;
			ft_putchar_fd('0', 1);
			i++;
		}
		if (k != 1)
			ft_putnbr_fd(p->itmp, 1);
		i = 0;
		while (i < p->tmpwidth - p->tmplen && i < p->tmpwidth - p->prec && p->just == 'r')
		{
			p->len++;
			ft_putchar_fd(p->padchar, 1);
			i++;
		}
		if (j == 1)
			p->tmpwidth++;
	}
	else
		ft_putnbr_fd(p->itmp, 1);
}
