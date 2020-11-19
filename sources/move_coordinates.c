/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:45:45 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 11:54:27 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	move_list_one(t_list **c_coordi, t_list **c_coordi_next)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *c_coordi;
	tmp2 = *c_coordi_next;
	if (tmp2->next != NULL)
		tmp = tmp2->next;
	*c_coordi = tmp;
	if (tmp->next != NULL)
		*c_coordi_next = tmp->next;
}

void	move_and_draw_coor(t_list **begin_list)
{
	t_list	*list;

	list = *begin_list;
	draw_background(&list);
	move_coor_ver(begin_list);
	move_coor_hor(begin_list);
	mlx_put_image_to_window(list->mlx, list->win, list->img, 0, 0);
	ft_bzero(list->data_addr, (list->m_width * list->m_height));
}

void	move_coor_hor(t_list **begin_list)
{
	int		rows;
	int		lines;
	t_list	*c_coordi;
	t_list	*c_coordi_next;

	c_coordi = *begin_list;
	c_coordi_next = c_coordi->next;
	lines = count_lines(begin_list);
	while (lines > 0)
	{
		rows = (count_rows(begin_list));
		while (rows > 1)
		{
			draw(*c_coordi, *c_coordi_next, begin_list);
			if (rows != 2)
				move_points_hor(&c_coordi, &c_coordi_next);
			rows--;
		}
		lines--;
		if (lines != 0)
			move_list_one(&c_coordi, &c_coordi_next);
	}
}

void	move_coor_ver(t_list **begin_list)
{
	int		rows;
	int		lines;
	t_list	*c_coordi;
	t_list	*c_coordi_next;

	c_coordi = *begin_list;
	rows = count_rows(begin_list);
	while (rows > 0)
	{
		c_coordi_next = c_coordi;
		lines = (count_lines(begin_list));
		while (lines > 0)
		{
			if (lines != 1)
			{
				move_points_ver2(&c_coordi_next, (count_rows(begin_list)));
				draw(*c_coordi, *c_coordi_next, begin_list);
				c_coordi = c_coordi_next;
			}
			lines--;
		}
		rows--;
		if (rows != 0)
			move_points_ver(begin_list, &c_coordi, rows);
	}
}
