/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:22:46 by tlandema          #+#    #+#             */
/*   Updated: 2018/12/07 11:50:02 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int	cleanse_1(int i, t_list **new, char ***tab)
{
	ft_lstdelone(new, &del_cont);
	ft_tabdel(3, tab);
	return (i);
}

int	cleanse_2(int i, char **line, char ***tab)
{
	ft_tabdel(i - 1, tab);
	free(*line);
	return (-1);
}

int	cleanse_3(int fd, int i, char **line, char ***tab)
{
	free(*line);
	while (get_next_line(fd, line) == 1)
		free(*line);
	ft_tabdel(i - 1, tab);
	return (-1);
}

int	usage(void)
{
	ft_putendl("fillit: missing file operand");
	return (0);
}

int	error(t_list **begin)
{
	ft_lstdel(begin, &del_cont);
	ft_putendl("error");
	return (0);
}
