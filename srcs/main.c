/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:51:05 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/13 14:11:56 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define COM (se.com == 0)
#define ANT (se.ants >= 0)
#define PARSE (ft_parse_sel(line, &se) == 2)
#define LOOKLINK (ft_p_room(line) == -1 || check_tiret(line) == 0)

int		end_lem_in(t_room *room, t_startend se)
{
	if (check_is_possible(se, 0) == 0)
		return (0);
	else
		return (algo(&room, se));
}

int		end_line(char *line, t_startend *se, t_room *room)
{
	if (se->com == 0 && se->ants >= 0 && ft_parse_sel(line, se) == 2
	&& ft_p_room(line) == -1 && se->antsgiven == 0)
	{
		if (check_link(se, line, room) == 2)
			ft_putendl(line);
	}
	if (se->n_link > 1 && ft_p_room(line) > 0)
	{
		ft_printf("%s : Error : wrong link -> Stop reading map\n", line);
		return (0);
	}
	se->com = 0;
	se->antsgiven = 0;
	ft_memdel((void **)&line);
	return (1);
}

int		main(void)
{
	char		*line;
	t_startend	se;
	t_room		*room;

	se = init_startend(&se);
	room = init_list_room();
	while (get_next_line(0, &line) == 1)
	{
		if (first_parse(line, &se) == 0)
			return (0);
		if (COM && ANT && PARSE && se.n_link == 0)
			if (parse_and_add_room(line, room, &se) == 0)
				return (0);
			if (COM && ANT && PARSE && LOOKLINK && se.antsgiven == 0)
		{
			if (check_link(&se, line, room) == 0)
				return (0);
			if (check_link(&se, line, room) == 1)
				break ;
		}
		if (end_line(line, &se, room) == 0)
			break ;
	}
	return (end_lem_in(room, se));
}
