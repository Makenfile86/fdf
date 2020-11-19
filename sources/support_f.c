/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:24:46 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 10:34:43 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "math.h"
#include "key_macos.h"

void	free_array(char **coordinates)
{
	size_t i;

	i = 0;
	while (coordinates[i])
		free(coordinates[i++]);
	free(coordinates);
}

void	reverse(t_list **begin_list, int reverse, int two_d)
{
	t_list	*tmp;

	tmp = *begin_list;
	while ((tmp) != NULL)
	{
		tmp->reverse = reverse;
		tmp->two_d = two_d;
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break ;
	}
}

void	draw_background(t_list **list)
{
	int			x;
	int			y;
	t_list		*coo;

	coo = *list;
	y = 0;
	x = 0;
	while (x < 1250)
	{
		y = 0;
		while (y < 1250)
		{
			put_pixel(coo, x, y, 000000);
			y++;
		}
		x++;
	}
}

int		count_rows(t_list **begin_list)
{
	t_list		*c_coordi;
	t_list		*tmp;
	int			count;

	count = 1;
	c_coordi = *begin_list;
	while ((c_coordi) && (c_coordi->next != NULL))
	{
		tmp = c_coordi->next;
		if (c_coordi->org_y == tmp->org_y)
		{
			if ((c_coordi->org_x != tmp->org_x) &&
					(c_coordi->org_y == tmp->org_y))
				count++;
			c_coordi = tmp;
		}
		else
			return (count);
	}
	return (count);
}

int		count_lines(t_list **begin_list)
{
	t_list		*c_coordi;
	t_list		*tmp;
	int			count;

	count = 1;
	c_coordi = *begin_list;
	while (c_coordi)
	{
		if (c_coordi->next != NULL)
		{
			tmp = c_coordi->next;
			if (c_coordi->org_y != tmp->org_y)
				count++;
			c_coordi = tmp;
		}
		else
			break ;
	}
	return (count);
}
