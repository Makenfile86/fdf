/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:05:43 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 10:08:25 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_macos.h"

int		read_file(const int fd, void *mlx_ptr, int x, int y)
{
	char	*line;
	char	**coordinates;
	void	*win_ptr;
	t_list	*list;

	list = NULL;
	while ((x = get_next_line(fd, &line)) == 1)
	{
		x = 0;
		coordinates = ft_strsplit(line, ' ');
		while (coordinates[x] != NULL)
		{
			create_linked_list(coordinates[x], &list, y, x);
			x++;
		}
		y++;
		free_array(coordinates);
		ft_strdel(&line);
	}
	list_reverse(&list);
	error_check(&list);
	find_max_values(&list);
	win_ptr = mlx_new_window(mlx_ptr, list->m_width, list->m_height, "1");
	init(list, mlx_ptr, win_ptr);
	return (1);
}
