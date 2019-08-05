/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_forming.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:15:03 by tlandema          #+#    #+#             */
/*   Updated: 2018/11/30 14:09:40 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetra_forming(t_vect **points)
{
	t_pt	tmp;

	tmp.x = (**points).pt1.x;
	tmp.y = (**points).pt1.y;
	if (tmp.x > (**points).pt2.x)
		tmp.x = (**points).pt2.x;
	if (tmp.x > (**points).pt3.x)
		tmp.x = (**points).pt3.x;
	if (tmp.x > (**points).pt4.x)
		tmp.x = (**points).pt4.x;
	(**points).pt1.x -= tmp.x;
	(**points).pt2.x -= tmp.x;
	(**points).pt3.x -= tmp.x;
	(**points).pt4.x -= tmp.x;
	if (tmp.y > (**points).pt2.y)
		tmp.y = (**points).pt2.y;
	if (tmp.y > (**points).pt3.y)
		tmp.y = (**points).pt3.y;
	if (tmp.y > (**points).pt4.y)
		tmp.y = (**points).pt4.y;
	(**points).pt1.y -= tmp.y;
	(**points).pt2.y -= tmp.y;
	(**points).pt3.y -= tmp.y;
	(**points).pt4.y -= tmp.y;
}
