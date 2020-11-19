/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:15:39 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 10:18:18 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

t_list	*ft_create_elem(char *coordinates, int y, int i)
{
	char	*color;
	t_list	*ret;

	if (!(color = ft_strnew(15 + 1)))
		error_message4();
	color = get_color(color, coordinates);
	if (!(ret = malloc(sizeof(t_list))))
		error_message4();
	ret->x = i;
	ret->y = y;
	ret->org_x = i;
	ret->org_y = y;
	ret->height = atoi(coordinates);
	ret->m_width = 1250;
	ret->m_height = 1250;
	ret->two_d = 0;
	ret->reverse = 0;
	ret->zoom = 0;
	ret->color = ft_atoi_base(color, 16);
	ret->bits_per_pixel = 32;
	ret->size_line = ret->m_width;
	ret->endian = 0;
	ret->next = NULL;
	ft_strdel(&color);
	return (ret);
}

void	list_reverse(t_list **begin_list)
{
	t_list	*previous;
	t_list	*next;
	t_list	*current;

	previous = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}

void	create_linked_list(char *coordinates, t_list **begin_list, int y, int i)
{
	t_list	*list_coo;

	coordinates_check(coordinates);
	list_coo = *begin_list;
	if (list_coo)
	{
		list_coo = ft_create_elem(coordinates, y, i);
		list_coo->next = *begin_list;
		*begin_list = list_coo;
	}
	else
		*begin_list = ft_create_elem(coordinates, y, i);
}
