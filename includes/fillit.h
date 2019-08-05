/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:01:03 by brichard          #+#    #+#             */
/*   Updated: 2018/12/07 11:26:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_pt
{
	int		x;
	int		y;
}				t_pt;

typedef struct	s_vect
{
	t_pt	pt1;
	t_pt	pt2;
	t_pt	pt3;
	t_pt	pt4;
	char	letter;
}				t_vect;

int				error(t_list **begin);
int				usage(void);
int				da_check_machine(t_list *current);
int				get_next_card(int fd, t_list **begin);
int				call_back(t_list *begin);

char			**create_final_tab(int size);

void			tetra_forming(t_vect **points);
void			fill_tab(t_vect *current, t_pt pts, char ***tab);
void			refresh(t_vect *current, t_pt coor, int size, char ***tab);
int				cleanse_1(int i, t_list **new, char ***tab);
int				cleanse_2(int i, char **line, char ***tab);
int				cleanse_3(int fd, int i, char **line, char ***tab);

#endif
