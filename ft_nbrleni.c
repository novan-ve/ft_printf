/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrleni.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:55:04 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/22 00:09:25 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrleni(long nb, int x)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0 && x == 0)
		i = 1;
	while (nb > 0 || nb < 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
