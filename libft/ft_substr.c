/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 01:10:18 by novan-ve      #+#    #+#                 */
/*   Updated: 2019/11/20 11:51:39 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if (start > len)
		return (ft_strdup(""));
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (start <= len)
	{
		while (s[i] != '\0' && i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
