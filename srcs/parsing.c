/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:11:43 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/06 17:51:39 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_startend(char *line, t_startend *se)
{
	if (ft_strequ("##start", line))
	{
		if (se->start == 0 && se->startgiven == 0)
		{
			se->start = 1;
			se->startgiven = 1;
		}
		else
			return (0);
	}
	if (ft_strequ("##end", line))
	{
		if (se->end == 0 && se->endgiven == 0)
		{
			se->end = 1;
			se->endgiven = 1;
		}
		else
			return (0);
	}
	return (1);
}

int			ft_parse_sel(char *line, t_startend *se)
{
	if (line[0] != '#')
		return (2);
	if (line[0] == '#' && line[1] == '#')
	{
		if (check_startend(line, se) == 0)
			return (0);
	}
	return (1);
}

static int	check_coor(char *line, int space)
{
	int i;

	i = 1;
	if (space == 1)
	{
		while (line[i] && line[i] != ' ')
		{
			if (ft_isdigit(line[i]) == 0)
				return (0);
			i++;
		}
	}
	else if (space == 2 && line[i] != '\0')
	{
		while (line[i])
		{
			if (ft_isdigit(line[i]) == 0)
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int			ft_p_room(char *line)
{
	int i;
	int ret;
	int space;
	int check;

	i = -1;
	ret = 0;
	space = 0;
	check = 0;
	while (line[++i])
	{
		if (line[i] == ' ')
		{
			space++;
			check = check + check_coor(&line[i], space);
		}
	}
	if (space == 0)
		return (-1);
	if (space != 2 || check != 2 || space == 0)
		return (0);
	i = -1;
	while (line[++i] != ' ')
		ret++;
	return (ret);
}
