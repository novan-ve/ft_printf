/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calcwidth.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:27:09 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/22 00:16:08 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_calcwidth(t_print *p)
{
	int		j;

	j = p->i;
	while (ft_isalpha(p->format[j]) == 0 && p->format[j] != '\0')
	{
		if (p->format[j] == '0' && p->format[j - 1] == '%')
			p->padchar = '0';
		else if (p->format[j] == '-')
			p->minus = 1;
		j++;
	}
	p->var = p->format[j];
	if (p->minus == 1)
	{
		p->just = 'r';
		p->padchar = ' ';
	}
	while (ft_isalpha(p->format[p->i]) == 0 && p->format[p->i] != '\0' && p->format[p->i] != '%')
	{
		if (p->format[p->i] == '*')
			p->tmpwidth = va_arg(p->args, int);
		if (p->format[p->i] == '.')
			break ;
		if (p->format[p->i] >= '0' && p->format[p->i] <= '9')
			p->tmpwidth = p->tmpwidth * 10 + p->format[p->i] - '0';
		p->i++;
	}
	if (p->format[p->i] == '.')
	{
		p->padchar = ' ';
		p->prec = 0;
		while (ft_isalpha(p->format[p->i]) == 0 && p->format[p->i] != '\0')
		{
			if (p->format[p->i] == '*')
				p->prec = va_arg(p->args, int);
			if (p->format[p->i] >= '0' && p->format[p->i] <= '9')
				p->prec = p->prec * 10 + p->format[p->i] - '0';
			p->i++;
		}
	}
}
