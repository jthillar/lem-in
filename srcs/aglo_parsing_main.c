/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aglo_parsing_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:52:27 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/12 18:17:02 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		first_parse(char *line, t_startend *se)
{
	if (line[0] == 'L')
		return (error(4, line));
	if (line[0] == '#' && line[1] != '#')
	{
		ft_putendl(line);
		se->com = 1;
	}
	if (se->com == 0 && se->ants == -1)
		se->ants = ft_parse_nb_ants(line, se);
	if (se->com == 0 && se->ants == -2)
		return (error(2, line));
	if (se->com == 0 && se->ants >= 0)
	{
		if (ft_parse_sel(line, se) == 0)
			return (error(1, line));
	}
	return (1);
}

int		check_link(t_startend *se, char *line, t_room *room)
{
	if (se->startgiven == 0 || se->endgiven == 0)
		return (error(5, line));
	if (ft_parse_link(line, &room, se) == 0)
	{
		if (se->write == 0)
		{
			ft_printf("%s : Error : wrong link -> Stop reading map\n", line);
			se->write = 1;
		}
		return (1);
	}
	se->n_link += 1;
	return (2);
}

int		check_roomname(t_room *room, char *line, int size)
{
	t_room	*tmp;
	char	*name;

	tmp = room;
	if (!(name = ft_strnew(size)))
		return (0);
	name = ft_strncpy(name, line, size);
	if (tmp->name)
	{
		while (tmp)
		{
			if (ft_strcmp(name, tmp->name) == 0)
			{
				ft_memdel((void**)&name);
				return (0);
			}
			tmp = tmp->next;
		}
	}
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&name);
	return (1);
}

int		parse_and_add_room(char *line, t_room *room, t_startend *se)
{
	if (ft_p_room(line) == 0)
		return (error(1, line));
	if (ft_p_room(line) >= 1)
	{
		if (check_roomname(room, line, ft_p_room(line)) == 0)
			return (error(6, line));
		ft_putendl(line);
		add_list_room(&room, line, ft_p_room(line), se);
		se->w_roomentry += 1;
	}
	return (1);
}
