/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:29:32 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/06 17:47:06 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ants	fill_t_ants(t_ants *a)
{
	a->cpt = 1;
	a->i_ants = 1;
	a->n = 2;
	a->i = 1;
	return (*a);
}

static t_ants	add_cpt(t_ants *a)
{
	a->cpt++;
	a->cpt_2++;
	return (*a);
}

void			print_result(t_startend *se, char **way, int nb_room)
{
	t_ants	a;

	a = fill_t_ants(&a);
	while (a.i_ants <= se->ants + nb_room - 2)
	{
		a.cpt_2 = 0;
		while (a.i > 0)
		{
			if (a.i >= nb_room)
				a.i--;
			if (a.cpt <= se->ants)
				ft_printf("L%d-%s ", a.cpt, way[a.i]);
			a.i--;
			if (a.n - 1 > 1)
				a = add_cpt(&a);
		}
		a.i = a.n;
		a.cpt = a.cpt - a.cpt_2;
		if (a.i_ants >= nb_room - 1)
			a.cpt++;
		if (a.n < nb_room)
			a.n++;
		ft_printf("\n");
		a.i_ants++;
	}
}

void			printway(char **way, int size)
{
	int i;

	i = 0;
	ft_printf("\nway : ");
	while (i < size)
	{
		ft_printf("%s", way[i]);
		if (i != size - 1)
			ft_printf(" - ");
		i++;
	}
	ft_printf("\n\n");
}
