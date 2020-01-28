/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:15:39 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/24 11:06:20 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

c_list	*ft_create_elem(char *coordinates, int y, int i)

{
	c_list	*ret;
	int		scale_x;
	int 	scale_y;

	scale_x = (i + 6);
	scale_y = (y + 8);

		if (!(ret = malloc(sizeof(c_list))))
			return (NULL);
	    ret->x = (scale_x * 25);
		ret->y = (scale_y * 25);
		ret->height = atoi(coordinates);
       	ret->next = NULL;
	return (ret);
}

void	create_linked_list(char *coordinates, c_list **begin_list, int y, int i)
{
	c_list	*list_coo;
	
	list_coo = *begin_list;
	if (list_coo)
	{
		while (list_coo->next)
			list_coo = list_coo->next;
		list_coo->next = ft_create_elem(coordinates, y, i);
	}
	else
		*begin_list = ft_create_elem(coordinates, y, i);
}
