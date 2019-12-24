/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dec_to_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:43:25 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/24 14:42:25 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strrev(t_print *p, int len)
{
	char	tmp[len];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (p->hex[i] != '\0')
	{
		tmp[i] = p->hex[i];
		i++;
	}
	tmp[i] = '\0';
	i--;
	while (i >= 0)
	{
		p->hex[j] = tmp[i];
		i--;
		j++;
	}
	p->hex[j] = '\0';
	p->tmplen = ft_strlen(p->hex);
}

void	ft_dec_to_hex(t_print *p, unsigned long dec, int x, int len)
{
	unsigned long	remainder;
	int				i;

	if (x == 0)
		x = 87;
	else if (x == 1)
		x = 55;
	i = 0;
	if (dec != 0 || p->var != 'p')
	{
		if (dec == 4294967296 && len == 16)
		{
			dec = 0;
			i = 1;
		}	
		while (dec != 0)
		{
			remainder = dec % 16;
			if (remainder < 10)
				p->hex[i] = 48 + remainder;
			else
				p->hex[i] = x + remainder;
			dec /= 16;
			i++;
		}
		p->hex[i] = '\0';
		ft_strrev(p, len);
	}
	else
	{
		p->hex[0] = '\0';
		p->tmplen = 5;
	}
}
