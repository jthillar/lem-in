/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:46:16 by jthillar          #+#    #+#             */
/*   Updated: 2017/10/12 13:16:33 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef struct		s_startend
{
	int				com;
	int				com2;
	int				start;
	int				end;
	int				start_link;
	int				startgiven;
	int				endgiven;
	int				w_roomentry;
	int				n_link;
	int				ants;
	int				antsgiven;
}					t_startend;

typedef struct		s_roomcomp
{
	int				r1;
	int				r2;
}					t_roomcomp;

typedef	struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				wei;
	int				order;
	struct s_tube	*tube;
	struct s_room	*next;
	struct s_tube	*firsttube;
}					t_room;

typedef	struct		s_tube
{
	struct s_room	*room;
	struct s_tube	*next;
	struct s_tube	*prev;
}					t_tube;

typedef struct		s_algo
{
	t_room	*tmp;
	t_room	*begin;
	int		i;
}					t_algo;

typedef	struct		s_ants
{
	int				i_ants;
	int				cpt;
	int				cpt_2;
	int				i;
	int				n;
}					t_ants;

int					ft_parse_sel(char *line, t_startend *se);
int					ft_p_room(char *line);
int					ft_parse_nb_ants(char *line, t_startend *se);
int					ft_parse_link(char *line, t_room **listroom,
					t_startend *se);

int					first_parse(char *line, t_startend *se);
int					check_link(t_startend *se, char *line, t_room *room);

int					parse_and_add_room(char *line, t_room *room,
					t_startend *se);

t_startend			init_startend(t_startend *se);
t_room				*init_list_room(void);
int					add_list_room(t_room **room, char *line, int size,
					t_startend *se);
t_tube				*init_list_tube(t_tube *tube);

int					pre_add_tube(char *room1, char *room2, t_room **room);
int					add_tube(char *room1, char *room2, t_room **listroom);
void				ft_first_tube(t_room **room, int i);

int					error(int nb, char *line);
int					check_is_possible(t_startend se, int n);

int					algo(t_room **room, t_startend se);

int					result_ants(t_room **room, int nb_room, t_startend *se);

void				printtube(t_room **room);
void				print_result(t_startend *se, char **way, int nb_room);
void				printway(char **way, int size);
#endif
