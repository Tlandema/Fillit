/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   da_check_machine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:05:23 by brichard          #+#    #+#             */
/*   Updated: 2018/12/06 17:27:17 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int		da_struct_maker(t_vect *points, int x, int y, int pt_num)
{
	if (pt_num > 4)
		return (0);
	else if (pt_num == 1)
	{
		(*points).pt1.x = x;
		(*points).pt1.y = y;
	}
	else if (pt_num == 2)
	{
		(*points).pt2.x = x;
		(*points).pt2.y = y;
	}
	else if (pt_num == 3)
	{
		(*points).pt3.x = x;
		(*points).pt3.y = y;
	}
	else if (pt_num == 4)
	{
		(*points).pt4.x = x;
		(*points).pt4.y = y;
	}
	return (1);
}

static int		check_dim(char **card)
{
	int		x;
	int		y;

	x = -1;
	while (card[++x])
	{
		y = 0;
		while (card[x][y])
			y++;
		if (y != 4)
			return (0);
	}
	if (x != 4)
		return (0);
	return (1);
}

static int		count_links(char **card, int x, int y)
{
	int		links;

	links = 0;
	if (x + 1 != 4 && card[x + 1][y] == '#')
		links++;
	if (x - 1 != -1 && card[x - 1][y] == '#')
		links++;
	if (y + 1 != 4 && card[x][y + 1] == '#')
		links++;
	if (y - 1 != -1 && card[x][y - 1] == '#')
		links++;
	return (links);
}

static int		in_da_loop(char **card, int *links, t_vect *points)
{
	int		x;
	int		y;
	int		pt_num;

	x = -1;
	pt_num = 0;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (card[x][y] == '#')
			{
				pt_num++;
				*links += count_links(card, x, y);
				if (!(da_struct_maker(points, x, y, pt_num)))
					return (0);
			}
			else if (card[x][y] != '.')
				return (0);
		}
	}
	return (1);
}

int				da_check_machine(t_list *current)
{
	int			links;
	char		**card;
	t_vect		*pts;
	static int	letter_index = 0;

	card = (char **)current->content;
	links = 0;
	if (!(pts = ft_memalloc(sizeof(t_vect))))
		return (0);
	if (!(check_dim(card)))
	{
		free(pts);
		return (0);
	}
	if (!(in_da_loop(card, &links, pts)))
	{
		free(pts);
		return (0);
	}
	tetra_forming(&pts);
	pts->letter = ('A' + letter_index);
	letter_index++;
	current->content = (void *)pts;
	return (links == 6 || links == 8 ? 1 : 0);
}
