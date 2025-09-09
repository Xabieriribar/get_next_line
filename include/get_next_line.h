/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiribar <xiribar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 00:00:00 by xirib             #+#    #+#             */
/*   Updated: 2025/09/04 00:00:00 by xirib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
# define BUFFER_SIZE 4096

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	ft_create_list(t_list **list, int fd);

#endif
