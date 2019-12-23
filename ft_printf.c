/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:24:22 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/23 23:50:18 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** cspdiuxX%  -0.*
*/

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_print	p;

	p.i = 0;
	p.len = 0;
	p.tmplen = 0;
	p.padchar = ' ';
	p.just = 'l';
	p.width = 0;
	p.minus = 0;
	p.tmpwidth = 0;
	p.prec = -1;
	p.error = 0;
	p.format = (char*)format;
	va_start(p.args, format);
	while (p.format[p.i] != '\0')
	{
		if (p.format[p.i] == '%')
			ft_format(&p);
		else
		{
			ft_putchar_fd(p.format[p.i], 1);
			p.len++;
		}
		if (p.error == 1)
			return (-1);
		p.i++;
		p.width += p.tmpwidth;
		p.tmpwidth = 0;
		p.len += p.tmplen;
		p.tmplen = 0;
		p.error = 0;
		p.minus = 0;
		p.prec = -1;
		p.just = 'l';
		if (p.len < p.width)
			p.len = p.width;
	}
	va_end(p.args);
	return (p.len);
}
