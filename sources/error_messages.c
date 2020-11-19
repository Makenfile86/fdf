/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:53:59 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/13 12:55:01 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_message(void)
{
	ft_putendl("error: bad map");
	exit(0);
}

void	error_message2(void)
{
	ft_putendl("error opening file, probably doesnt exist");
	exit(0);
}

void	error_message3(void)
{
	ft_putendl("error reading file");
	exit(0);
}

void	error_message4(void)
{
	ft_putendl("error while allocating memory");
	exit(0);
}
