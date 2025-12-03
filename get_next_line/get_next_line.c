/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obutolin <obutolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:13:37 by obutolin          #+#    #+#             */
/*   Updated: 2025/12/01 09:36:23 by obutolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_reststr_from_list(t_list **list)
{
	t_list	*last_item;
	char	*rest_str;
	int		i;
	int		index;

	last_item = find_last_item(*list);
	if (last_item == NULL || last_item->buff == NULL)
		return (NULL);
	rest_str = malloc(BUFFER_SIZE + 1);
	if (rest_str == NULL)
		return (NULL);
	index = index_newline_character(last_item);
	if (index == -1)
		return (free(rest_str), rest_str = NULL, NULL);
	index++;
	i = 0;
	while (last_item->buff[index] != '\0')
		rest_str[i++] = last_item->buff[index++];
	rest_str[i] = '\0';
	return (rest_str);
}

char	*get_nextline_from_list(t_list *list)
{
	size_t	length;
	size_t	i;
	size_t	k;
	char	*nextline;

	if (list == NULL)
		return (NULL);
	length = get_nextline_length(list);
	nextline = malloc(length + 1);
	if (nextline == NULL)
		return (NULL);
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buff[i] != '\0')
		{
			nextline[k++] = list->buff[i++];
			if (list->buff[i - 1] == '\n')
				break ;
		}
		list = list->next;
	}
	nextline[k] = '\0';
	return (nextline);
}

// read_fd() reads from file descriptor (fd) piece of BUFFER_SIZE to list
// Result can be:
// 1-ok,
// 2-end of file
// 0-errors
int	read_fd(int fd, t_list **list)
{
	char	*buf;
	int		bytes_read;

	while (index_newline_character(*list) == -1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (0);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), buf = NULL, 0);
		if (bytes_read == 0)
			return (free(buf), buf = NULL, 2);
		buf[bytes_read] = '\0';
		if (!append_new_item(list, buf))
			return (free(buf), buf = NULL, 0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*nextline;
	char			*rest_str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (free_list(&list), NULL);
	if (!read_fd(fd, &list))
		return (free_list(&list), NULL);
	nextline = get_nextline_from_list(list);
	if (nextline == NULL)
		return (free_list(&list), NULL);
	rest_str = get_reststr_from_list(&list);
	free_list(&list);
	if (rest_str == NULL)
		return (free(rest_str), rest_str = NULL, nextline);
	if (rest_str[0] == '\0')
		return (free(rest_str), rest_str = NULL, nextline);
	append_new_item(&list, rest_str);
	return (nextline);
}
