/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:32:40 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/17 09:53:43 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int		ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	const char	*digits2 = "0123456789abcdef";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == (c) || digits2[i] == (c))
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] != '0')
		error_message();
	i++;
	if (str[i] != 'x')
		error_message();
	i++;
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)(result));
}

char	*get_color(char *color, char *coordinates)
{
	int i;
	int y;
	int count;

	count = 0;
	i = 0;
	y = 0;
	while (coordinates[i] != '\0')
	{
		if (coordinates[i] == ',')
		{
			count = 1;
			i++;
			while (coordinates[i] != '\0')
			{
				color[y] = coordinates[i];
				y++;
				i++;
			}
		}
		i++;
	}
	if (count != 1)
		color[y] = '\0';
	return (color);
}

int		color(t_list c_coordi, t_list c_coordi_next)
{
	int color;

	if (c_coordi.color != 0 && c_coordi.reverse != 1)
		return (c_coordi.color);
	if (((c_coordi.height >= 0 && c_coordi.height < 4) ||
(c_coordi_next.height >= 0 && c_coordi_next.height < 4)))
		color = 0x9A1F6A;
	if (((c_coordi.height >= 4 && c_coordi.height < 7) ||
(c_coordi_next.height >= 4 && c_coordi_next.height < 7)))
		color = 0xF3AF3D;
	if ((c_coordi.height >= 7) || (c_coordi_next.height >= 7))
		color = 0xEF8633;
	if (c_coordi.reverse == 1)
		color = 000000;
	return (color);
}
