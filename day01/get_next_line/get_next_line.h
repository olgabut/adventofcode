/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obutolin <obutolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:14:53 by obutolin          #+#    #+#             */
/*   Updated: 2025/07/12 17:44:00 by obutolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*buff;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		index_newline_character(t_list *list);
int		append_new_item(t_list **list, char *str);
size_t	get_nextline_length(t_list *list);
t_list	*find_last_item(t_list *list);
void	free_list(t_list **list);

#endif