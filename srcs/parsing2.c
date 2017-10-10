/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:01:36 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/06 17:52:53 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_parse_nb_ants(char *line)
{
	int nb_ants;
	int i;

	if (line[0] == '#')
		return (-1);
	i = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (-2);
	}
	if (!(nb_ants = ft_atoi(line)))
		return (-2);
	if (nb_ants <= 0)
		return (-2);
	ft_putendl(line);
	return (nb_ants);
}

static int	ft_parse_link2(char *line, char **room1, char **room2, int i)
{
	if (!(*room1 = ft_strnew(i)))
		return (0);
	*room1 = ft_strncpy(*room1, line, i);
	if (!(*room2 = ft_strnew(ft_strlen(line) - (i + 1))))
		return (0);
	*room2 = ft_strncpy(*room2, &line[i + 1], ft_strlen(line) - (i + 1));
	return (1);
}

static int	start_link_ok(int n, int start)
{
	if (start == 1 || n == 1)
		return (1);
	return (0);
}

int			ft_room_compare(char *room1, char *room2, t_room **room,
			t_startend *se)
{
	t_roomcomp	r;
	t_room		*listroom;

	r.r1 = 0;
	r.r2 = 0;
	listroom = *room;
	if (ft_strcmp(room1, room2) == 0)
		return (0);
	while (listroom)
	{
		if (ft_strcmp(room1, listroom->name) == 0)
		{
			r.r1 = 1;
			se->start_link = start_link_ok(se->start_link, listroom->start);
		}
		if (ft_strcmp(room2, listroom->name) == 0)
		{
			r.r2 = 1;
			se->start_link = start_link_ok(se->start_link, listroom->start);
		}
		listroom = listroom->next;
	}
	if (r.r1 == 1 && r.r2 == 1)
		return (pre_add_tube(room1, room2, room));
	return (0);
}

int			ft_parse_link(char *line, t_room **listroom, t_startend *se)
{
	char	*room1;
	char	*room2;
	int		i;
	int		cpt;

	cpt = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '-')
		{
			cpt++;
			if (cpt == 1)
				cpt = ft_parse_link2(line, &room1, &room2, i);
		}
	}
	if (cpt != 1 || ft_strlen(room2) == 0)
		return (0);
	return (ft_room_compare(room1, room2, listroom, se));
}
