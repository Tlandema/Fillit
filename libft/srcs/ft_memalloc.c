/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:28:32 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 16:20:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size == 0)
		return (NULL);
	if (!(s = (void*)malloc(size)))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
