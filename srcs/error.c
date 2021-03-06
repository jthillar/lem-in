/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:24:06 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/12 17:57:10 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	error(int nb, char *line)
{
	ft_printf("%s -> ", line);
	if (nb == 1)
		ft_putendl("Error : Wrong room entry");
	if (nb == 2)
		ft_putendl("Error : Wrong ants number");
	if (nb == 3)
		ft_putendl("Error : Wrong link room");
	if (nb == 4)
		ft_putendl("Error : Starting with a L is not possible");
	if (nb == 5)
		ft_putendl("Error : No start or end room");
	if (nb == 6)
		ft_putendl("Error : Room already exists");
	return (0);
}

int	check_is_possible(t_startend se, int n)
{
	if (n == 0 && se.ants <= 0)
	{
		ft_putendl("Error : Wrong ants number");
		return (0);
	}
	if (n == 0 && (se.n_link < 2 || se.w_roomentry < 2))
		ft_putendl("Error : Not enough room");
	else if (n == 1)
		ft_putendl("Error : No possible way");
	else
		return (1);
	return (0);
}
