/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prints.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 16:52:41 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/24 15:54:27 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints(t_print *p)
{
	int		i;
	int		j;

	i = 0;
	j = 6;
	p->strtmp = va_arg(p->args, char*);
	if (p->strtmp == NULL)
		i = -1;
	else
		p->tmplen = ft_strlen(p->strtmp);
	if (p->padchar == '0')
		p->padchar = ' ';
	if (p->tmplen < p->tmpwidth && p->prec == -1 && i == 0)
	{
		if (p->just == 'r')
			ft_putstr_fd(p->strtmp, 1);
		while (i < (p->tmpwidth - p->tmplen))
		{
			ft_putchar_fd(p->padchar, 1);
			i++;
		}
		if (p->just == 'l')
			ft_putstr_fd(p->strtmp, 1);
		if (p->tmplen < p->tmpwidth)
			p->tmplen = p->tmpwidth;
	}
	else if (p->prec >= 0 && i == 0)
	{
		if (p->prec == p->tmpwidth && p->prec > p->tmplen)
			p->prec = p->tmplen;
		else if (p->prec == p->tmpwidth)
			p->tmplen = p->prec;
		if (p->prec > p->tmplen)
			p->prec = p->tmplen;
		if (p->just == 'r')
			ft_putprec_fd(p->strtmp, 1, p->prec);
		while (i < (p->tmpwidth - p->prec))
		{
			ft_putchar_fd(p->padchar, 1);
			i++;
		}
		if (p->just == 'l')
			ft_putprec_fd(p->strtmp, 1, p->prec);
		if (p->prec < p->tmplen)
			p->tmplen = p->prec;
		if (p->tmplen < p->tmpwidth)
			p->tmplen = p->tmpwidth;
	}
	else if (p->prec == -1 && i == 0)
		ft_putstr_fd(p->strtmp, 1);
	else if (i == -1)
	{
		i = 0;
		if (p->prec == -1 || p->prec > 5)
			p->tmplen = 6;
		if (p->prec < 6)
			j = 0;
		if (p->just == 'r' && (p->prec == -1 || p->prec > 5))
			ft_putstr_fd("(null)", 1);
		while (i < (p->tmpwidth - j) && i < (p->tmpwidth - p->tmplen))
		{
			ft_putchar_fd(p->padchar, 1);
			i++;
		}
		if (p->just == 'l' && (p->prec == -1 || p->prec > 5))
			ft_putstr_fd("(null)", 1);
	}
}
