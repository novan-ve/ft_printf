/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:45:27 by novan-ve      #+#    #+#                 */
/*   Updated: 2019/11/20 12:01:15 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == 0)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
