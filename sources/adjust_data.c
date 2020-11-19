/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:21:06 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 14:57:46 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

void	check_scale_values(int *scale_x, int *scale_y)
{
	if (*scale_x < 5)
		*scale_x = (*scale_x + 2);
	if (*scale_y < 5)
		*scale_y = (*scale_y + 2);
	if (*scale_x > 50 && *scale_x < 75)
		*scale_x = (*scale_x - 15);
	if (*scale_y > 50 && *scale_y < 75)
		*scale_y = (*scale_y - 15);
}

void	check_max_values(t_list *tmp, int *max_x, int *max_y)
{
	if (*max_x == 1)
		tmp->max_x = 0;
	if (*max_y == 1)
		tmp->max_y = 0;
	tmp->max_x = *max_x;
	tmp->max_y = *max_y;
}

void	find_max_values(t_list **begin_list)
{
	int		max_negative;
	int		max_y;
	int		max_x;
	t_list	*tmp;

	tmp = *begin_list;
	max_negative = 0;
	while (tmp != NULL)
	{
		if ((ft_isnegative(tmp->height) == 1) && (tmp->height < max_negative))
			max_negative = tmp->height;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	if (max_negative < 0)
		max_negative = (max_negative * (-1));
	max_y = tmp->org_y;
	max_x = tmp->org_x;
	if (max_y == 0)
		max_y = 1;
	if (max_x == 0)
		max_x = 1;
	adjust_data(begin_list, max_negative, max_x, max_y);
}

void	adjust_data(t_list **begin_list, int max_negative, int max_x, int max_y)
{
	int		scale_x;
	int		scale_y;
	t_list	*tmp;

	tmp = *begin_list;
	scale_x = (625 / (max_x - tmp->zoom));
	scale_y = (525 / (max_y - tmp->zoom));
	while (tmp)
	{
		check_max_values(tmp, &max_x, &max_y);
		tmp->max_negative = max_negative;
		if (tmp->one_time != 1)
			tmp->height = (tmp->height + max_negative);
		tmp->x = (tmp->org_x * scale_x);
		tmp->y = (tmp->org_y * scale_y);
		if (tmp->two_d == 0)
			iso(&tmp->x, &tmp->y, tmp->height);
		tmp->x = (tmp->x + 500);
		tmp->y = (tmp->y + 450);
		tmp->one_time = 1;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
