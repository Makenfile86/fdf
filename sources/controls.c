/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:22:32 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 14:32:22 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_macos.h"

void	move_left(t_list **list)
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
			reverse(&map, 0, 0);
		else
			reverse(&map, 0, 1);
		while (map != NULL)
		{
			map->org_x = (map->org_x - 1);
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}

void	move_right(t_list **list)
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
			reverse(&map, 0, 0);
		else
			reverse(&map, 0, 1);
		while (map != NULL)
		{
			map->org_x = (map->org_x + 1);
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}

void	move_down(t_list **list)
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
			map->org_y = (map->org_y + 1);
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}

void	move_up(t_list **list)
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
			map->org_y = (map->org_y - 1);
			if (map->next == NULL)
				break ;
			map = map->next;
		}
		map = *list;
		adjust_data(&map, map->max_negative, map->max_x, map->max_y);
		move_and_draw_coor(&map);
	}
}

int		keypressed(int keycode, t_list *map)
{
	if (map)
	{
		if (keycode == MAIN_PAD_ESC)
			exit(0);
		if (keycode == NUM_PAD_5)
			two_d_display(&map);
		if (keycode == NUM_PAD_6)
			move_left(&map);
		if (keycode == NUM_PAD_4)
			move_right(&map);
		if (keycode == NUM_PAD_8)
			move_down(&map);
		if (keycode == NUM_PAD_2)
			move_up(&map);
		if (keycode == NUM_PAD_7)
			zoom_in(&map);
		if (keycode == NUM_PAD_9)
			zoom_out(&map);
		if (keycode == NUM_PAD_1)
			height_up(&map);
		if (keycode == NUM_PAD_3)
			height_down(&map);
	}
	return (0);
}
