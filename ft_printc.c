/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 16:44:48 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/18 15:47:35 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printc(t_print *p)
{
	int		i;

	i = 0;
	p->tmplen++;
	if (p->just == 'r')
		ft_putchar_fd((unsigned int)va_arg(p->args, char*), 1);
	while (i < (p->tmpwidth - 1))
	{
		ft_putchar_fd(p->padchar, 1);
		i++;
	}
	if (p->just == 'l')
		ft_putchar_fd((unsigned int)va_arg(p->args, char*), 1);
}
