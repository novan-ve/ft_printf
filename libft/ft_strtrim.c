/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 10:56:27 by novan-ve      #+#    #+#                 */
/*   Updated: 2019/11/20 11:19:03 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		front;
	size_t		back;

	if (s1 == 0 || set == 0)
		return (0);
	front = 0;
	while (ft_strchr(set, s1[front]) && s1[front] != '\0')
		front++;
	back = ft_strlen(s1);
	if (front >= back)
	{
		str = malloc(1);
		*str = '\0';
		return (str);
	}
	while (ft_strchr(set, s1[back - 1]))
		back--;
	str = (char*)malloc(sizeof(char) * (back - front) + 1);
	if (str == 0)
		return (str);
	ft_strlcpy(str, s1 + front, (back - front) + 1);
	return (str);
}
