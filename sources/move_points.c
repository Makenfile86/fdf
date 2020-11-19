/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:35:00 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 10:41:15 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_macos.h"

void	move_points_ver2(t_list **c_coordi_next, int move)
{
	t_list	*tmp;

	tmp = *c_coordi_next;
	while (move > 0)
	{
		tmp = tmp->next;
		move--;
	}
	*c_coordi_next = tmp;
}

void	move_points_line(t_list **c_coordi, t_list **c_coordi_next)
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

void	move_points_ver(t_list **begin_list, t_list **c_coordi, int rows)
{
	t_list *tmp;

	tmp = *begin_list;
	while (rows > 0 && tmp->next != NULL)
	{
		tmp = tmp->next;
		rows--;
	}
	*c_coordi = tmp;
}

void	move_points_hor(t_list **c_coordi, t_list **c_coordi_next)
{
	t_list *tmp;

	*c_coordi = *c_coordi_next;
	tmp = *c_coordi;
	if (tmp->next != NULL)
		*c_coordi_next = tmp->next;
}
