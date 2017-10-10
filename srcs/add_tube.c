/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:21:23 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/04 11:36:48 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		pre_add_tube(char *room1, char *room2, t_room **room)
{
	if (add_tube(room1, room2, room) == 0)
		return (0);
	ft_memdel((void**)&room1);
	ft_memdel((void**)&room2);
	return (1);
}

int		add_room_tube(t_room *room, t_tube *tube)
{
	t_tube *tmp;

	if (tube->room)
	{
		while (tube && tube->next)
			tube = tube->next;
		if (!(tube->next = (t_tube*)malloc(sizeof(t_tube))))
			return (0);
		tmp = tube;
		tube = tube->next;
		tube->prev = tmp;
	}
	tube->room = room;
	tube->next = NULL;
	return (1);
}

int		add_tube(char *room1, char *room2, t_room **listroom)
{
	t_room	*tmp1;
	t_room	*tmp2;

	tmp1 = *listroom;
	tmp2 = *listroom;
	while (ft_strcmp(room1, tmp1->name) != 0)
		tmp1 = tmp1->next;
	if (tmp1->tube == NULL)
		if (!(tmp1->tube = init_list_tube(tmp1->tube)))
			return (0);
	while (ft_strcmp(room2, tmp2->name) != 0)
		tmp2 = tmp2->next;
	if (tmp2->tube == NULL)
		if (!(tmp2->tube = init_list_tube(tmp2->tube)))
			return (0);
	if (add_room_tube(tmp1, tmp2->tube) == 0
	|| add_room_tube(tmp2, tmp1->tube) == 0)
		return (0);
	return (1);
}

void	ft_first_tube(t_room **room, int i)
{
	t_room	*tmp;

	tmp = *room;
	if (i == 1)
	{
		while (tmp)
		{
			tmp->firsttube = tmp->tube;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			tmp->tube = tmp->firsttube;
			tmp = tmp->next;
		}
	}
}
