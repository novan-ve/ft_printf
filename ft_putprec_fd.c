/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putprec_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 17:44:11 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/18 17:46:15 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putprec_fd(char *s, int fd, int prec)
{
	int		i;

	i = 0;
	if (s)
		while (s[i] != '\0' && i < prec)
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
}
