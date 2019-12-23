/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:27:44 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/23 17:12:21 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef	struct	s_print
{
	char		*format;
	va_list		args;
	int			i;
	int			len;
	int			tmplen;
	char		*strtmp;
	char		hex[16];
	int			itmp;
	char		padchar;
	int			width;
	int			tmpwidth;
	char		just;
	int			minus;
	char		var;
	int			error;
	int			prec;
}				t_print;

int				ft_printf(const char *format, ...);
void			ft_uputnbr_fd(unsigned int n, int fd);
void			ft_dec_to_hex(t_print *p, unsigned long dec, int x, int len);
int				ft_nbrleni(long nb, int x);
int				ft_nbrlenu(unsigned int nb, int x);
void			ft_printc(t_print *p);
void			ft_format(t_print *p);
void			ft_prints(t_print *p);
void			ft_printi(t_print *p);
void			ft_printp(t_print *p);
void			ft_printu(t_print *p);
void			ft_printx(t_print *p, int x);
void			ft_calcwidth(t_print *p);
void			ft_putprec_fd(char *s, int fd, int prec);

#endif
