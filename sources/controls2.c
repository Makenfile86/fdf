/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:13:55 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 14:22:10 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_macos.h"

void	check_map(t_list *map)
{
	if (map->two_d == 1)
		reverse(&map, 1, 1);
	else
		reverse(&map, 1, 0);
}

void	check_map2(t_list *map)
{
	if (map->two_d == 0)
		reverse(&map, 0, 0);
	else
		reverse(&map, 0, 1);
}

void	zoom_in(t_list **list)
{
	t_list *map;

	map = *list;
	if (map)
	{
		check_map(map);
		move_and_draw_coor(&map);
		check_map2(map);
		if (map->max_x > map->max_y)
			map->org_max = map->max_y;
		else
			map->org_max = map->max_x;
		while (map != NULL)
		{
			if ((map->org_max - (map->zoom + (map->max_x / 18)) > 0))
				map->zoom = (map->zoom + (map->max_x / 18));
			map->org_max = map->org_max - 1;
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}

void	zoom_out(t_list **list)
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
			map->zoom = (map->zoom - (map->max_x / 18));
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}

void	two_d_display(t_list **list)
{
	t_list *map;

	map = *list;
	if (map)
	{
		if (map->two_d == 1)
			reverse(&map, 1, 1);
		else
			reverse(&map, 1, 0);
		move_and_draw_coor(&map);
		if (map->two_d == 0)
		{
			reverse(&map, 0, 1);
			adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		}
		else
		{
			reverse(&map, 0, 0);
			adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		}
		move_and_draw_coor(&map);
	}
}
