/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 14:52:02 by novan-ve       #+#    #+#                */
/*   Updated: 2019/12/24 00:01:11 by anon          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*str = "Hello World";
	int		i = -200;
	int		len;

	/*
	** String			%s
	*/
	len = ft_printf("%s", str);
	printf("\t\t:%i\n", len);
	len = printf("%s", str);
	printf("\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Int				%i
	*/
	len = ft_printf("%i", -1234567);
	printf("\t\t:%i\n", len);
	len = printf("%i", -1234567);
	printf("\t\t:%i\n", len);
	ft_printf("\n");
	len = ft_printf("%d", 12345678);
	printf("\t\t:%i\n", len);
	len = printf("%d", 12345678);
	printf("\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Character		%c
	*/
	len = ft_printf("%c", 'c');
	printf("\t\t\t:%i\n", len);
	len = printf("%c", 'c');
	printf("\t\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** No Flags			Test
	*/
	len = ft_printf("Test");
	printf("\t\t\t:%i\n", len);
	len = printf("Test");
	printf("\t\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** String and int	%s%i
	*/
	len = ft_printf("Test, %s%i", "test", 2);
	printf("\t\t:%i\n", len);
	len = printf("Test, %s%i", "test", 2);
	printf("\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Pointer			%p
	*/
	printf("Ft_printf:\n");
	len = ft_printf("%p", &str);
	printf("\t\t:%i\n", len);
	printf("Printf:\n");
	len = printf("%p", &str);
	printf("\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Unsigned int		%u
	*/
	len = ft_printf("%u", i);
	printf("\t\t:%i\n", len);
	len = printf("%u", i);
	printf("\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Percentage		%%
	*/
	len = ft_printf("%%%%");
	printf("\t\t\t:%i\n", len);
	len = printf("%%%%");
	printf("\t\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Unsigned hex int	%x
	*/
	len = ft_printf("%x", 273859);
	printf("\t\t\t:%i\n", len);
	len = printf("%x", 273859);
	printf("\t\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Unsigned HEX int	%X
	*/
	len = ft_printf("%X", 273859);
	printf("\t\t\t:%i\n", len);
	len = printf("%X", 273859);
	printf("\t\t\t:%i\n", len);
	ft_printf("\n");
	/*
	** Width		%13
	*/
	printf("%%10d%%013s\n");
	len = ft_printf("%10d%013s", 123, str);
	printf("\t:%i\n", len);
	len = printf("%10d%013s", 123, str);
	printf("\t:%i\n", len);
	ft_printf("\n");
	printf("%%010d%%013s\n");
	len = ft_printf("%010d%013s", 123, str);
	printf("\t:%i\n", len);
	len = printf("%010d%013s", 123, str);
	printf("\t:%i\n", len);
	ft_printf("\n");
	/*
	** Width errors	%-0
	*/
	printf("%%-10d%%013s\n");
	len = ft_printf("%-10d%013s", 123, str);
	printf("\t:%i\n", len);
	len = printf("%-10d%013s", 123, str);
	printf("\t:%i\n", len);
	ft_printf("\n");
	printf("%%-010d%%013s\n");
	len = ft_printf("%-010d%013s", 123, str);
	printf("\t:%i\n", len);
	len = printf("%-010d%013s", 123, str);
	printf("\t:%i\n", len);
	ft_printf("\n");
	printf("%%0-10d%%013s\n");
	len = ft_printf("%0-10d%013s", 123, str);
	printf("\t:%i\n", len);
	len = printf("%0-10d%013s", 123, str);
	printf("\t:%i\n", len);
	ft_printf("\n");
	 printf("%%--10-d%%013s\n");
	 len = ft_printf("%--10-d%013s", 123, str);
	 printf("\t:%i\n", len);
	 len = printf("%--10-d%013s", 123, str);
	 printf("\t:%i\n", len);
	 ft_printf("\n");
	/*
	** Precision errors	%.
	*/
	printf("%%8.4s\n");
	len = ft_printf("%8.4s", "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%8.4s", "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%08.4s\n");
	len = ft_printf("%08.4s", "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%08.4s", "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%-8.4s\n");
	len = ft_printf("%-8.4s", "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%-8.4s", "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%8.0s\n");
	len = ft_printf("%8.0s", "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%8.0s", "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%08.0s\n");
	len = ft_printf("%08.0s", "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%08.0s", "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%-8.0s\n");
	len = ft_printf("%-8.0s", "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%-8.0s", "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%0.8s\n");
	len = ft_printf("%0.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%0.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%00.8s\n");
	len = ft_printf("%00.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%00.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%-0.8s\n");
	len = ft_printf("%-0.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%-0.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%0.0s\n");
	len = ft_printf("%0.0s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%0.0s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%00.0s\n");
	len = ft_printf("%00.0s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%00.0s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%-0.0s\n");
	len = ft_printf("%-0.0s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%-0.0s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%4.8s\n");
	len = ft_printf("%4.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%4.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%04.8s\n");
	len = ft_printf("%04.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%04.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%-4.8s\n");
	len = ft_printf("%-4.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%-4.8s", "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	/*
	** Field width var	%*
	*/
	printf("%%*.4s, 8\n");
	len = ft_printf("%*.4s", 8, "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%*.4s", 8, "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%0*.4s, 8\n");
	len = ft_printf("%0*.4s", 8, "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%0*.4s", 8, "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%-*.4s, 8\n");
	len = ft_printf("%-*.4s", 8, "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%-*.4s", 8, "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%*.0s, 8\n");
	len = ft_printf("%*.0s", 8, "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%*.0s", 8, "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%0*.0s, 8\n");
	len = ft_printf("%0*.0s", 8, "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%0*.0s", 8, "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%-*.0s, 8\n");
	len = ft_printf("%-*.0s", 8, "Hello");
	printf("\t\t:%i\n", len);
	len = printf("%-*.0s", 8, "Hello");
	printf("\t\t:%i\n", len);
	printf("\n");
	printf("%%0.*s, 8\n");
	len = ft_printf("%0.*s", 8, "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%0.*s", 8, "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%00.*s, 8\n");
	len = ft_printf("%00.*s", 8, "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%00.*s", 8, "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%-0.*s, 8\n");
	len = ft_printf("%-0.*s", 8, "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%-0.*s", 8, "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%*.*s, 0, 0\n");
	len = ft_printf("%*.*s", 0, 0, "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%*.*s", 0, 0,"Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%0*.*s, 0, 0\n");
	len = ft_printf("%0*.*s", 0, 0, "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%0*.*s", 0, 0, "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	printf("%%-*.*s, 0, 0\n");
	len = ft_printf("%-*.*s", 0, 0, "Hello");
	printf("\t\t\t:%i\n", len);
	len = printf("%-*.*s", 0, 0, "Hello");
	printf("\t\t\t:%i\n", len);
	printf("\n");
	/*
	** NULL str
	*/
	printf("%%sE, NULL\n");
	len = ft_printf("%sE", NULL);
	printf("\t\t\t:%i\n", len);
	len = printf("%sE", NULL);
	printf("\t\t\t:%i\n", len);
	printf("%%.03sE, NULL\n");
	len = ft_printf("%.03sE", NULL);
	printf("\t\t\t:%i\n", len);
	len = printf("%.03sE", NULL);
	printf("\t\t\t:%i\n", len);
	printf("%%.06sE, NULL\n");
	len = ft_printf("%.06sE", NULL);
	printf("\t\t\t:%i\n", len);
	len = printf("%.06sE", NULL);
	printf("\t\t\t:%i\n", len);
	printf("%%3.1sE, NULL\n");
	len = ft_printf("%3.1sE", NULL);
	printf("\t\t\t:%i\n", len);
	len = printf("%3.1sE", NULL);
	printf("\t\t\t:%i\n", len);
	printf("%%3.6sE, NULL\n");
	len = ft_printf("%3.6sE", NULL);
	printf("\t\t\t:%i\n", len);
	len = printf("%3.6sE", NULL);
	printf("\t\t\t:%i\n", len);
	printf("%%20.6sE, NULL\n");
	len = ft_printf("%20.6sE", NULL);
	printf("\t:%i\n", len);
	len = printf("%20.6sE", NULL);
	printf("\t:%i\n", len);
	printf("%%-3.8sE, NULL\n");
	len = ft_printf("%-3.8sE", NULL);
	printf("\t\t\t:%i\n", len);
	len = printf("%-3.8sE", NULL);
	printf("\t\t\t:%i\n", len);
	printf("%%-10.8sE, NULL\n");
	len = ft_printf("%-10.8sE", NULL);
	printf("\t\t:%i\n", len);
	len = printf("%-10.8sE", NULL);
	printf("\t\t:%i\n", len);
	printf("%%-9.1sE, NULL\n");
	len = ft_printf("%-9.1sE", NULL);
	printf("\t\t:%i\n", len);
	len = printf("%-9.1sE", NULL);
	printf("\t\t:%i\n", len);
	printf("%%-3.1sE, NULL\n");
	len = ft_printf("%-3.1sE", NULL);
	printf("\t\t\t:%i\n", len);
	len = printf("%-3.1sE", NULL);
	printf("\t\t\t:%i\n", len);
	printf("%%-8.sE, NULL\n");
	len = ft_printf("%-8.sE", NULL);
	printf("\t\t:%i\n", len);
	len = printf("%-8.sE", NULL);
	printf("\t\t:%i\n", len);
	printf("%%5%%\n");
	len = ft_printf("%5%");
	printf("\t\t\t:%i\n", len);
	len = printf("%5%");
	printf("\t\t\t:%i\n", len);
	printf("%%-5%%\n");
	len = ft_printf("%-5%");
	printf("\t\t\t:%i\n", len);
	len = printf("%-5%");
	printf("\t\t\t:%i\n", len);
	/*
	**	Int pft
	*/
	printf("%%3iE, 0\n");
	len = ft_printf("%3iE", 0);
	printf("\t\t:%i\n", len);
	len = printf("%3iE", 0);
	printf("\t\t:%i\n", len);
	printf("%%-3iE, 0\n");
	len = ft_printf("%-3iE", 0);
	printf("\t\t:%i\n", len);
	len = printf("%-3iE", 0);
	printf("\t\t:%i\n", len);
	printf("%%.5iE, 2\n");
	len = ft_printf("%.5iE", 2);
	printf("\t\t:%i\n", len);
	len = printf("%.5iE", 2);
	printf("\t\t:%i\n", len);
	printf("%%.6iE, -3\n");
	len = ft_printf("%.6iE", -3);
	printf("\t\t:%i\n", len);
	len = printf("%.6iE", -3);
	printf("\t\t:%i\n", len);
	printf("%%8.5iE, 34\n");
	len = ft_printf("%8.5iE", 34);
	printf("\t\t:%i\n", len);
	len = printf("%8.5iE", 34);
	printf("\t\t:%i\n", len);
	printf("------------------------------\n");
	printf("%%7iE, -14\n");
	len = ft_printf("%7iE", -14);
	printf("\t\t:%i\n", len);
	len = printf("%7iE", -14);
	printf("\t\t:%i\n", len);
	printf("%%-7iE, -14\n");
	len = ft_printf("%-7iE", -14);
	printf("\t\t:%i\n", len);
	len = printf("%-7iE", -14);
	printf("\t\t:%i\n", len);
	printf("%%07iE, -54\n");
	len = ft_printf("%07iE", -54);
	printf("\t\t:%i\n", len);
	len = printf("%07iE", -54);
	printf("\t\t:%i\n", len);
	printf("%%10.5iE, -216\n");
	len = ft_printf("%10.5iE", -216);
	printf("\t\t:%i\n", len);
	len = printf("%10.5iE", -216);
	printf("\t\t:%i\n", len);
	printf("%%8.3iE, 8375\n");
	len = ft_printf("%8.3iE", 8375);
	printf("\t\t:%i\n", len);
	len = printf("%8.3iE", 8375);
	printf("\t\t:%i\n", len);
	printf("%%8.3iE, -8473\n");
	len = ft_printf("%8.3iE", -8473);
	printf("\t\t:%i\n", len);
	len = printf("%8.3iE", -8473);
	printf("\t\t:%i\n", len);
	printf("%%-10.5iE, -216\n");
	len = ft_printf("%-10.5iE", -216);
	printf("\t\t:%i\n", len);
	len = printf("%-10.5iE", -216);
	printf("\t\t:%i\n", len);
	printf("%%16sE, NULL\n");
	len = ft_printf("%16sE", NULL);
	printf("\t\t:%i\n", len);
	len = printf("%16sE", NULL);
	printf("\t\t:%i\n", len);
	printf("%%-16sE, NULL\n");
	len = ft_printf("%-16sE", NULL);
	printf("\t\t:%i\n", len);
	len = printf("%-16sE", NULL);
	printf("\t\t:%i\n", len);
	printf("%%-8sE, NULL\n");
	len = ft_printf("%-8sE", NULL);
	printf("\t\t:%i\n", len);
	len = printf("%-8sE", NULL);
	printf("\t\t:%i\n", len);
	/*
	**	nocrash test
	*/
	printf("%%5\n");
	len = ft_printf("%5");
	printf("\t\t:%i\n", len);
	len = printf("%5");
	printf("\t\t:%i\n", len);
	printf("%%05\n");
	len = ft_printf("%05");
	printf("\t\t:%i\n", len);
	len = printf("%05");
	printf("\t\t:%i\n", len);
	printf("%%-05\n");
	len = ft_printf("%-05");
	printf("\t\t:%i\n", len);
	len = printf("%-05");
	printf("\t\t:%i\n", len);
	len = ft_printf("%%04.3i 42 == |%04.3i|\x0a", 42);
	printf("\t\t:%i\n", len);
	len = printf("%%04.3i 42 == |%04.3i|\x0a", 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%04.2i 42 == |%04.2i|\x0a", 42);
	printf("\t\t:%i\n", len);
	len = printf("%%04.2i 42 == |%04.2i|\x0a", 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%04i 42 == |%04i|\x0a", 42);
	printf("\t\t:%i\n", len);
	len = printf("%%04i 42 == |%04i|\x0a", 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%05i 42 == |%05i|\x0a", 42);
	printf("\t\t:%i\n", len);
	len = printf("%%05i 42 == |%05i|\x0a", 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%-4d 42 == |%-4d|\x0a", 42);
	printf("\t\t:%i\n", len);
	len = printf("%%-4d 42 == |%-4d|\x0a", 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%-5i 42 == |%-5i|\x0a", -42);
	printf("\t\t:%i\n", len);
	len = printf("%%-5i 42 == |%-5i|\x0a", -42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("|%3i|%-3i\x0a", 42, 42);
	printf("\t\t:%i\n", len);
	len = printf("|%3i|%-3i\x0a", 42, 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%-4i 42 == |%-4i|\x0a", 42);
	printf("\t\t:%i\n", len);
	len = printf("%%-4i 42 == |%-4i|\x0a", 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%*i 42 == |%*i|\x0a", 5, 42);
	printf("\t\t:%i\n", len);
	len = printf("%%*i 42 == |%*i|\x0a", 5, 42);
	printf("\t\t:%i\n\n", len);
	len = ft_printf("%%*i 42 == |%*i|\x0a", 3, 42);
	printf("\t\t:%i\n", len);
	len = printf("%%*i 42 == |%*i|\x0a", 3, 42);
	printf("\t\t:%i\n", len);
	return (0);
}
