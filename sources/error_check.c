/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:47:07 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 12:53:40 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coordinates_check(char *coordinates)
{
	int i;

	i = 0;
	while (coordinates[i] != '\0')
	{
		if (coordinates[i] == '-')
			i++;
		if (ft_isdigit(coordinates[i]) == 0)
		{
			if (coordinates[i] == ',')
				return (1);
			else
				error_message();
		}
		i++;
	}
	return (0);
}

int		error_check(t_list **begin_list)
{
	t_list	*tmp;
	int		row_count;
	int		compare;
	int		line;

	tmp = *begin_list;
	line = 0;
	if (tmp == NULL)
		error_message();
	row_count = count_rows(begin_list);
	while (tmp != NULL && tmp->next != NULL)
	{
		compare = 0;
		while (tmp->y == line)
		{
			compare++;
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		if (row_count != compare)
			error_message();
		line++;
	}
	return (1);
}
