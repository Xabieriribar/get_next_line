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

void	create_list(t_list **list, int fd)
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
