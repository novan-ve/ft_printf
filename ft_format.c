/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:45:07 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/23 17:35:46 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(t_print *p)
{
	p->i++;
	if (p->format[p->i] == '-' || p->format[p->i] == '.')
		ft_calcwidth(p);
	else if (p->format[p->i] >= '0' && p->format[p->i] <= '9')
		ft_calcwidth(p);
	else if (p->format[p->i] == '*')
		ft_calcwidth(p);
	if (p->format[p->i] == 's')
		ft_prints(p);
	else if (p->format[p->i] == 'i' || p->format[p->i] == 'd')
		ft_printi(p);
	else if (p->format[p->i] == 'c')
		ft_printc(p);
	else if (p->format[p->i] == 'p')
		ft_printp(p);
	else if (p->format[p->i] == 'u')
		ft_printu(p);
	else if (p->format[p->i] == '%')
	{
		p->tmpwidth = 1;
		ft_putchar_fd('%', 1);
		p->len++;
	}
	else if (p->format[p->i] == 'x')
		ft_printx(p, 0);
	else if (p->format[p->i] == 'X')
		ft_printx(p, 1);
	else
		p->error = 1;
}
