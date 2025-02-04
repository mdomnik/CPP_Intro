/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:40:25 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/04 23:59:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point&	Point::operator=(Point const &other)
{
	(void)other;
	return *this;
}

Point::~Point(void) {}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }