/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uputnbr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:14:36 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/17 17:37:20 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	if (n < 0)
		ft_putnbr_fd(4294967295 - -n, fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
