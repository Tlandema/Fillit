/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   izdis_daplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:07:49 by brichard          #+#    #+#             */
/*   Updated: 2018/12/07 12:18:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	izdis_daplace(t_list *current, t_pt coor, int size, char **tab)
{
	t_pt	c_pt1;
	t_pt	c_pt2;
	t_pt	c_pt3;
	t_pt	c_pt4;

	c_pt1.x = ((t_vect*)current->content)->pt1.x + coor.x;
	c_pt1.y = ((t_vect*)current->content)->pt1.y + coor.y;
	c_pt2.x = ((t_vect*)current->content)->pt2.x + coor.x;
	c_pt2.y = ((t_vect*)current->content)->pt2.y + coor.y;
	c_pt3.x = ((t_vect*)current->content)->pt3.x + coor.x;
	c_pt3.x = ((t_vect*)current->content)->pt3.x + coor.x;
	c_pt3.y = ((t_vect*)current->content)->pt3.y + coor.y;
	c_pt4.x = ((t_vect*)current->content)->pt4.x + coor.x;
	c_pt4.y = ((t_vect*)current->content)->pt4.y + coor.y;
	if (c_pt1.x > size || c_pt1.y > size || tab[c_pt1.x][c_pt1.y] != '.')
		return (-1);
	else if (c_pt2.x > size || c_pt2.y > size || tab[c_pt2.x][c_pt2.y] != '.')
		return (-1);
	else if (c_pt3.x > size || c_pt3.y > size || tab[c_pt3.x][c_pt3.y] != '.')
		return (-1);
	else if (c_pt4.x > size || c_pt4.y > size || tab[c_pt4.x][c_pt4.y] != '.')
		return (-1);
	return (current->next == NULL ? 0 : 1);
}

static int	tetri_posing(t_list *lst, int size, char ***tab)
{
	t_pt	coor;
	int		ret;

	coor.x = -1;
	while (++coor.x < size)
	{
		coor.y = -1;
		while (++coor.y < size)
		{
			ret = izdis_daplace(lst, coor, size - 1, *tab);
			if (ret == 0)
			{
				fill_tab(((t_vect*)lst->content), coor, tab);
				return (0);
			}
			if (ret == 1)
			{
				fill_tab(((t_vect*)lst->content), coor, tab);
				if (tetri_posing(lst->next, size, tab) == 0)
					return (0);
				refresh(((t_vect*)lst->content), coor, size, tab);
			}
		}
	}
	return (-1);
}

int			call_back(t_list *begin)
{
	int		size;
	char	**tab;

	size = 2;
	if (!(tab = create_final_tab(size)))
		return (0);
	while (tetri_posing(begin, size, &tab) == -1)
	{
		ft_tabdel(size - 1, &tab);
		if (!(tab = create_final_tab(++size)))
			return (0);
	}
	ft_print_tab(tab);
	ft_tabdel(size - 1, &tab);
	return (1);
}
