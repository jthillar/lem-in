/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:35:50 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/06 17:49:22 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	result_ants(t_room **room, int nb_room, t_startend *se)
{
	char	**way;
	t_room	*tmp;

	tmp = *room;
	if (!(way = (char**)malloc(sizeof(char*) * (nb_room + 1))))
		return (0);
	while (tmp)
	{
		if (tmp->wei == 1)
		{
			if (!(way[tmp->order] = (char*)malloc(sizeof(char) *
			(ft_strlen(tmp->name) + 1))))
				return (0);
			ft_strcpy(way[tmp->order], tmp->name);
		}
		tmp = tmp->next;
	}
	printway(way, nb_room + 1);
	if (se->ants + nb_room - 2 < 0)
		ft_putendl("Error : too much ants and/or rooms");
	print_result(se, way, nb_room + 1);
	ft_memdel((void**)way);
	return (1);
}
