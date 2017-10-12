/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:31:40 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/12 13:55:39 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*start_list(t_room **room)
{
	t_room *tmp;

	tmp = *room;
	while (tmp && tmp->start != 1)
		tmp = tmp->next;
	return (tmp);
}

static t_room	*ft_reinit(t_room **room, t_room *begin, t_room *tmp)
{
	tmp->wei = 2;
	tmp = *room;
	while (tmp)
	{
		if (tmp->wei == 1 && tmp->start == 0)
		{
			tmp->wei = 0;
			tmp->order = 0;
		}
		tmp = tmp->next;
	}
	return (begin);
}

static t_room	*next_tube(t_room *tmp)
{
	while (tmp->tube && tmp->tube->room->wei != 0)
		tmp->tube = tmp->tube->next;
	return (tmp);
}

static t_room	*good_order_tube(t_room *tmp, int i)
{
	tmp = tmp->tube->room;
	tmp->wei = 1;
	tmp->order = i;
	return (tmp);
}

int				algo(t_room **room, t_startend se)
{
	t_algo	algo;

	algo.i = 0;
	algo.tmp = start_list(room);
	algo.begin = algo.tmp;
	ft_first_tube(room, 1);
	while (algo.tmp->end != 1)
	{
		if (algo.tmp->tube && algo.tmp->tube->room->wei == 0)
		{
			algo.i += 1;
			algo.tmp = good_order_tube(algo.tmp, algo.i);
		}
		else
			algo.tmp = next_tube(algo.tmp);
		if (!algo.tmp->tube)
		{
			if (algo.tmp->start == 1)
				return (check_is_possible(se, 1));
			algo.tmp = ft_reinit(room, algo.begin, algo.tmp);
			algo.i = 0;
		}
	}
	ft_first_tube(room, 0);
	return (result_ants(room, algo.tmp->order, &se));
}
