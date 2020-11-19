/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:25:53 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/17 09:25:57 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_macos.h"

void	height_up(t_list **list)
{
	t_list *map;

	map = *list;
	if (map)
	{
		check_map(map);
		move_and_draw_coor(&map);
		check_map2(map);
		while (map != NULL)
		{
			map->height = map->height * 2;
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}

void	height_down(t_list **list)
{
	t_list *map;

	map = *list;
	if (map)
	{
		check_map(map);
		move_and_draw_coor(&map);
		check_map2(map);
		while (map != NULL)
		{
			map->height = map->height / 2;
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}
