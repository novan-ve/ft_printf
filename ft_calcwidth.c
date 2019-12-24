/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calcwidth.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:27:09 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/24 20:15:39 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_calcwidth2(t_print *p, int x, int j)
{
	if (x == 0)
	{
		p->var = p->format[j];
		if (p->minus == 1)
		{
			p->just = 'r';
			p->padchar = ' ';
		}
	}
	else if (x == 1 && p->format[p->i] == '.')
	{
		j = 0;
		p->padchar = ' ';
		p->prec = 0;
		while (ft_isalpha(p->format[p->i]) == 0 && p->format[p->i] != '\0')
		{
			if (p->format[p->i] == '%')
				break ;
			if (p->format[p->i] == '*')
				p->prec = va_arg(p->args, int);
			if (p->format[p->i] >= '0' && p->format[p->i] <= '9')
				p->prec = p->prec * 10 + p->format[p->i] - '0';
			p->i++;
		}
	}
}

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
	ft_calcwidth2(p, 0, j);
	while (ft_isalpha(p->format[p->i]) == 0 && p->format[p->i] != '\0')
	{
		if (p->format[p->i] == '%')
			break ;
		if (p->format[p->i] == '*')
			p->tmpwidth = va_arg(p->args, int);
		if (p->format[p->i] == '.')
			break ;
		if (p->format[p->i] >= '0' && p->format[p->i] <= '9')
			p->tmpwidth = p->tmpwidth * 10 + p->format[p->i] - '0';
		p->i++;
	}
	ft_calcwidth2(p, 1, j);
}
