/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:51:05 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/12 13:24:22 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define COM (se.com == 0)
#define ANT (se.ants >= 0)
#define PARSE (ft_parse_sel(line, &se) == 2)

int		end_lem_in(t_room *room, t_startend se)
{
	if (check_is_possible(se, 0) == 0)
		return (0);
	else
		return (algo(&room, se));
}

void	end_line(char *line, t_startend *se, t_room *room)
{
	if (se->com == 0 && se->ants >= 0 && ft_parse_sel(line, se) == 2
	&& ft_p_room(line) == -1 && se->antsgiven == 0)
	{
		if (check_link(se, line, room) == 2)
			ft_putendl(line);
	}
	se->com = 0;
	se->antsgiven = 0;
	ft_memdel((void **)&line);
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
		{
			if (parse_and_add_room(line, room, &se) == 0)
				return (0);
		}
		if (COM && ANT && PARSE && ft_p_room(line) == -1 && se.antsgiven == 0)
		{
			if (check_link(&se, line, room) == 0)
				return (0);
			if (check_link(&se, line, room) == 1)
				break ;
		}
		end_line(line, &se, room);
	}
	return (end_lem_in(room, se));
}
