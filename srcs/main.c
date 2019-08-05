/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastien <brichard@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:53:22 by bastien           #+#    #+#             */
/*   Updated: 2018/12/07 12:13:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	t_list	*begin;
	int		fd;
	int		ret;

	begin = NULL;
	if (ac != 2)
		return (usage());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (error(&begin));
	ret = 1;
	while (ret > 0)
		ret = get_next_card(fd, &begin);
	if (ret == 0 && begin == NULL)
		return (error(&begin));
	if (ret < 0)
		return (error(&begin));
	if (!(call_back(begin)))
		return (error(&begin));
	if (close(fd) == -1)
		return (error(&begin));
	ft_lstdel(&begin, &del_cont);
	return (0);
}
