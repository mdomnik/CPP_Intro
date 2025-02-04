/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:40:38 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/04 23:58:56 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

static Fixed cross(Point const &a, Point const &b, Point const &p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross1 = cross(a, b, point);
	Fixed cross2 = cross(b, c, point);
	Fixed cross3 = cross(c, a, point);


	if (cross1 == 0 || cross2 == 0 || cross3 == 0)
		return false;
	if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0))
		return true;

	return false;
}
