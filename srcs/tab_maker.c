/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:10:50 by tlandema          #+#    #+#             */
/*   Updated: 2018/12/07 12:11:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define PT1X current->pt1.x + coor.x
#define PT1Y current->pt1.y + coor.y
#define PT2X current->pt2.x + coor.x
#define PT2Y current->pt2.y + coor.y
#define PT3X current->pt3.x + coor.x
#define PT3Y current->pt3.y + coor.y
#define PT4X current->pt4.x + coor.x
#define PT4Y current->pt4.y + coor.y

void	fill_tab(t_vect *current, t_pt coor, char ***tab)
{
	(*tab)[PT1X][PT1Y] = current->letter;
	(*tab)[PT2X][PT2Y] = current->letter;
	(*tab)[PT3X][PT3Y] = current->letter;
	(*tab)[PT4X][PT4Y] = current->letter;
}

void	refresh(t_vect *current, t_pt coor, int size, char ***tab)
{
	if (PT1X < size && PT1Y < size)
		(*tab)[PT1X][PT1Y] = '.';
	if (PT2X < size && PT2Y < size)
		(*tab)[PT2X][PT2Y] = '.';
	if (PT3X < size && PT3Y < size)
		(*tab)[PT3X][PT3Y] = '.';
	if (PT4X < size && PT4Y < size)
		(*tab)[PT4X][PT4Y] = '.';
}

char	**create_final_tab(int size)
{
	char	**tab;
	int		count;

	tab = NULL;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	count = 0;
	while (count < size)
	{
		if (!(tab[count] = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		{
			ft_tabdel(count - 1, &tab);
			return (NULL);
		}
		ft_memset(tab[count], '.', size);
		count++;
	}
	return (tab);
}
