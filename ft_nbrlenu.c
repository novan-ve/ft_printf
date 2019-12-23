/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlenu.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:46:27 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/23 22:51:06 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlenu(unsigned int nb, int x)
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
