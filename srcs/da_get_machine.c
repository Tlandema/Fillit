/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   da_get_machine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:57:02 by brichard          #+#    #+#             */
/*   Updated: 2018/12/07 11:24:43 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int	read_card(int fd, char ***tab)
{
	int		ret;
	int		i;
	int		err;
	char	*line;

	i = 0;
	err = 0;
	while (i < 5 && (ret = get_next_line(fd, &line)) > 0)
	{
		if (err == 21 && ret == 1)
			return (cleanse_3(fd, i, &line, tab));
		err = ret;
		if (i != 4 && *line)
		{
			if (!((*tab)[i] = ft_strdup(line)))
				return (cleanse_2(i, &line, tab));
		}
		else if (*line)
			return (cleanse_2(i, &line, tab));
		free(line);
		i++;
	}
	if (ret == -1)
		ft_tabdel(i - 1, tab);
	return (ret);
}

int			get_next_card(int fd, t_list **begin)
{
	int		ret;
	char	**tab;
	t_list	*new;

	if (!(new = ft_lstnew(NULL, 0)))
		return (-1);
	if (!(tab = (char **)ft_memalloc(sizeof(char*) * 5)))
	{
		ft_lstdelone(&new, &del_cont);
		return (-1);
	}
	tab[4] = NULL;
	if ((ret = read_card(fd, &tab)) < 0)
	{
		ft_lstdelone(&new, &del_cont);
		return (-1);
	}
	if (ret == 0 && *tab == NULL)
		return (cleanse_1(0, &new, &tab));
	new->content = (void *)tab;
	if (da_check_machine(new) == 0)
		return (cleanse_2(4, (char**)&new, &tab));
	ft_tabdel(3, &tab);
	ft_lstapp(begin, new);
	return (1);
}
