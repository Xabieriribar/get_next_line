/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 00:00:00 by xirib             #+#    #+#             */
/*   Updated: 2025/09/12 10:58:13 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_clean_list(t_list **lst)
{
	t_list	*next_node;
	t_list	*last_node;
	int		i;
	int		k;
	char	*buffer;

	i = 0;
	k = 0;
	if (!lst || !*lst)
		return ;
	last_node = ft_lstlast(*lst);
	next_node = malloc(sizeof(t_list));
	if (!next_node)
		return ;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	if (last_node->buffer[i] == '\n')
		i++;
	while (last_node->buffer[i++])
		k++;
	buffer = malloc(k + 1);
	if (!buffer)
	{
		ft_lstclear(&next_node, del);
		return ;
	}
	i -= k;
	k = 0;
	while (last_node->buffer[i])
		buffer[k++] = last_node->buffer[i++];
	buffer[k] = '\0';
	next_node->buffer = buffer;
	next_node->next = NULL;
	deallocate(lst, next_node, buffer);
}

char	*ft_get_line(t_list *lst)
{
	int		len_to_newline;
	char	*next_line;

	if (lst == NULL)
		return (NULL);
	len_to_newline = ft_list_len(lst);
	next_line = malloc(len_to_newline + 1);
	if (!next_line)
		return (NULL);
	next_line = ft_feed_buffer(lst, next_line);
	return (next_line);
}

void	ft_create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*bffr;

	while (!found_newline(*list))
	{
		bffr = malloc(BUFFER_SIZE + 1);
		if (!bffr)
			return ;
		chars_read = read(fd, bffr, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(bffr);
			ft_lstclear(list, del);
			return ;
		}
		else if (chars_read == 0)
		{
			free(bffr);
			break ;
		}
		bffr[chars_read] = '\0';
		append(list, bffr);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[OPEN_MAX];
	char	*next_line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	ft_create_list(&list[fd], fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = ft_get_line(list[fd]);
	ft_clean_list(&list[fd]);
	return (next_line);
}
