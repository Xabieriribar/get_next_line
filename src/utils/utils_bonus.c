/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xabieriribarrevuelta@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 00:00:00 by xirib             #+#    #+#             */
/*   Updated: 2025/09/11 09:30:09 by xiribar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	found_newline(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
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

void	append(t_list **list, char *bffr)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node -> next = new_node;
	new_node -> buffer = bffr;
	new_node -> next = NULL;
}

char	*ft_feed_buffer(t_list *lst, char *bffr_to_feed)
{
	int	i;
	int	k;

	if (lst == NULL || bffr_to_feed == NULL)
		return (NULL);
	k = 0;
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
	bffr_to_feed[k++] = '\n';
	bffr_to_feed[k] = '\0';
	return (bffr_to_feed);
}

void	deallocate(t_list **lst, t_list *next_node, char *buffer)
{
	ft_lstclear(lst, del);
	if (next_node -> buffer[0] != '\0')
	{
		*lst = next_node;
	}
	else
	{
		free(buffer);
		free(next_node);
	}
}
