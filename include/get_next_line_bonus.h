/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xiribar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 00:00:00 by xirib             #+#    #+#             */
/*   Updated: 2025/09/04 00:00:00 by xirib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
# define OPEN_MAX 10240
# endif

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

int		found_newline(t_list *lst);
void	append(t_list **list, char *bffr);
t_list	*ft_lstlast(t_list *lst);
int		ft_list_len(t_list *list);
char	*ft_feed_buffer(t_list *lst, char *bffr_to_feed);
void	deallocate(t_list **lst, t_list *next_node, char *buffer);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	del(void *content);

#endif
