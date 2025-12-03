/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obutolin <obutolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:40 by obutolin          #+#    #+#             */
/*   Updated: 2025/07/12 17:44:32 by obutolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_nextline_length(t_list *list)
{
	size_t	length;
	size_t	i;

	length = 0;
	while (list)
	{
		i = 0;
		while (list->buff[i] != '\0')
		{
			if (list->buff[i] == '\n')
			{
				length++;
				return (length);
			}
			i++;
			length++;
		}
		list = list->next;
	}
	return (length);
}

t_list	*find_last_item(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// 1-ok
// 0-error
int	append_new_item(t_list **list, char *str)
{
	t_list	*new_item;
	t_list	*last_item;

	new_item = malloc(sizeof(t_list));
	if (new_item == NULL)
		return (0);
	last_item = find_last_item(*list);
	if (last_item == NULL)
		*list = new_item;
	else
		last_item->next = new_item;
	new_item->buff = str;
	new_item->next = NULL;
	return (1);
}

// is_newline_character() returns
// (-1) - there is NOT '\n' character
// num  - index of '\n' characer
int	index_newline_character(t_list *list)
{
	t_list	*last_item;
	int		i;

	last_item = find_last_item(list);
	if (last_item == NULL)
		return (-1);
	i = 0;
	while (last_item->buff && last_item->buff[i] != '\0')
	{
		if (last_item->buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buff);
		(*list)->buff = NULL;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}
