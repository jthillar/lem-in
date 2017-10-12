/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:27:41 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/12 14:40:37 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_startend	init_startend(t_startend *se)
{
	se->com = 0;
	se->com2 = 0;
	se->start = 0;
	se->end = 0;
	se->startgiven = 0;
	se->endgiven = 0;
	se->start_link = 0;
	se->w_roomentry = 0;
	se->n_link = 0;
	se->ants = -1;
	se->antsgiven = 0;
	se->write = 0;
	return (*se);
}

t_tube		*init_list_tube(t_tube *tube)
{
	if (!(tube = (t_tube*)malloc(sizeof(t_tube))))
		return (NULL);
	if (tube)
	{
		tube->room = NULL;
		tube->next = NULL;
		tube->prev = NULL;
	}
	return (tube);
}

t_room		*init_list_room(void)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (room)
	{
		room->name = NULL;
		room->start = 0;
		room->end = 0;
		room->order = 0;
		room->tube = NULL;
		room->next = NULL;
	}
	return (room);
}

int			add_list_room(t_room **room, char *line, int size, t_startend *se)
{
	if ((*room)->name)
	{
		while (*room && (*room)->next)
			*room = (*room)->next;
		if (!((*room)->next = (t_room*)malloc(sizeof(t_room))))
			return (0);
		*room = (*room)->next;
	}
	if (!((*room)->name = ft_strnew(size)))
		return (0);
	ft_strncpy((*room)->name, line, size);
	(*room)->start = se->start;
	se->start = 0;
	(*room)->end = se->end;
	se->end = 0;
	(*room)->wei = 0;
	(*room)->order = 0;
	if ((*room)->start == 1)
		(*room)->wei = 1;
	(*room)->tube = NULL;
	(*room)->firsttube = NULL;
	(*room)->next = NULL;
	return (1);
}
