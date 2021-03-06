/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:59:59 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 10:05:17 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_macos.h"

int		main(int argc, char **argv)
{
	void		*mlx_ptr;
	int			fd;
	int			y;
	int			x;

	mlx_ptr = mlx_init();
	x = 0;
	y = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fdf 'input map'\n");
		return (0);
	}
	if (!((fd = open(argv[1], O_RDONLY)) >= 0))
		error_message2();
	if (!(read_file(fd, mlx_ptr, x, y)))
		error_message3();
	close(fd);
	return (0);
}
