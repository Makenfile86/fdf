/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:59:33 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/17 09:50:07 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	get_delta_sign_val(t_list *c_coordi, t_list *c_coordi_next,
		t_point *delta, t_point *sign)
{
	delta->x = c_coordi_next->x - c_coordi->x;
	sign->x = ((delta->x > 0) - (delta->x < 0));
	delta->x = ABS(delta->x) << 1;
	delta->y = c_coordi_next->y - c_coordi->y;
	sign->y = ((delta->y > 0) - (delta->y < 0));
	delta->y = ABS(delta->y) << 1;
}

void	readjust_point(t_point *delta, t_point *sign,
		t_list *c_coord, int *error)
{
	int dx;
	int dy;
	int sx;
	int sy;

	dx = delta->x;
	dy = delta->y;
	sx = sign->x;
	sy = sign->y;
	if ((*error >= 0) && (*error || (dy > 0)))
	{
		*error -= dy;
		c_coord->x += sx;
	}
	*error += dx;
	c_coord->y += sy;
}

void	adjust_point(t_point *delta, t_point *sign, t_list *c_coord, int *error)
{
	int dx;
	int dy;
	int sx;
	int sy;

	dx = delta->x;
	dy = delta->y;
	sx = sign->x;
	sy = sign->y;
	if ((*error >= 0) && (*error || (sx > 0)))
	{
		*error -= dx;
		c_coord->y += sy;
	}
	*error += dy;
	c_coord->x += sx;
}

void	draw(t_list coord, t_list coord_next, t_list **list)
{
	int		err;
	t_point	delta;
	t_point	sign;

	get_delta_sign_val(&coord, &coord_next, &delta, &sign);
	put_pixel(*list, coord.x, coord.y, color(coord, coord_next));
	if (delta.x >= delta.y)
	{
		err = (delta.y - (delta.x >> 1));
		while (coord.x != coord_next.x)
		{
			adjust_point(&delta, &sign, &coord, &err);
			put_pixel(*list, coord.x, coord.y, color(coord, coord_next));
		}
	}
	else
	{
		err = (delta.x - (delta.y >> 1));
		while (coord.y != coord_next.y)
		{
			readjust_point(&delta, &sign, &coord, &err);
			put_pixel(*list, coord.x, coord.y, color(coord, coord_next));
		}
	}
}

void	put_pixel(t_list *list, int x, int y, int color)
{
	int i;

	if (x < list->m_width && y >= 0 && y < list->m_height)
	{
		i = (x * list->bits_per_pixel / 8) + (y * list->size_line);
		list->data_addr[i] = color & 0xFF;
		list->data_addr[++i] = color >> 8 & 0xFF;
		list->data_addr[++i] = color >> 16 & 0xFF;
		list->data_addr[++i] = color >> 24;
	}
}
