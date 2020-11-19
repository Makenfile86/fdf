/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:58:19 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 14:59:06 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init(t_list *list, void *mlx_ptr, void *win_ptr)
{
	list->win = win_ptr;
	list->mlx = mlx_ptr;
	mlx_key_hook(list->win, keypressed, list);
	list->img = mlx_new_image(list->mlx, list->m_width, list->m_height);
	list->data_addr = mlx_get_data_addr(list->img, &(list->bits_per_pixel),
										&(list->size_line), &(list->endian));
	move_and_draw_coor(&list);
	mlx_loop(mlx_ptr);
}
