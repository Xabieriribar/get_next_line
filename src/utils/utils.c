/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xiribar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 00:00:00 by xirib             #+#    #+#             */
/*   Updated: 2025/09/04 00:00:00 by xirib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *lst)
{
	int	i;

	i = 0;
	while(lst)
	{
		i = 0;
		while (lst -> buffer[i])
		{
			if (lst->buffer[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

char	*ft_feed_buffer(t_list *lst, char *bffr_to_feed)
{
	int	i;
	int	k;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		i = 0;
		while (lst->buffer[i])
		{
			if (lst->buffer[i] == '\n')
			{
				bffr_to_feed[k++] = '\n';
				bffr_to_feed[k] = '\0';
				return (bffr_to_feed);
			}
			bffr_to_feed[k++] = lst->buffer[i++];
		}
		lst = lst->next;
	}
	return (bffr_to_feed);
}

int	ft_list_len(t_list *list)
{
	int	len;
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	append(t_list **list, char *bffr)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node =	ft_lstlast(*list);
	new_node =	malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (last_node == NULL)
	{
		*list = new_node;
	}
	else
		last_node -> next = new_node;
	new_node -> buffer = bffr;
	new_node -> next = NULL;
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
		if (!chars_read)
		{
			free(bffr);
			return ;
		}
		bffr[chars_read] = '\0';
		append(list, bffr);
	}
}

char	*ft_get_line(t_list *lst)
{
	int		len_to_newline;
	char	*next_line;

	len_to_newline = ft_list_len(lst);
	if (lst == NULL)
		return (NULL);
	next_line = malloc(len_to_newline + 1);
	next_line = ft_feed_buffer(lst, next_line);
	return (next_line);
}

void	del(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> buffer);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp1;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		temp1 = temp->next;
		ft_lstdelone(temp, del);
		temp = temp1;
	}
	*lst = NULL;
}

void	deallocate(t_list **lst, t_list *next_node, char *buffer)
{
	ft_lstclear(lst, del);
	if (next_node -> buffer[0])
	{
		*lst = next_node;
	}
	else
	{
		free(buffer);
		free(next_node);
	}
}

void	ft_clean_list(t_list **lst)
{
	t_list	*next_node;
	t_list	*last_node;
	int		i;
	int		k;
	char	*buffer;

	i = 0;
	k = 0;
	last_node = ft_lstlast(*lst);
	next_node = malloc(sizeof(t_list));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!next_node)
		return ;
	while (last_node->buffer[i] != '\0' && last_node->buffer[i] != '\n')
		++i;
	while (last_node->buffer[i] != '\0' && last_node->buffer[++i])
		buffer[k++] = last_node->buffer[i];
	deallocate(lst, next_node, buffer);
}
