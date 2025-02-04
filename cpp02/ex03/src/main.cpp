/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:18 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/04 23:58:30 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

void runTest(Point const &a, Point const &b, Point const &c, Point const &p, bool expected)
{
	bool result = bsp(a, b, c, p);
	std::cout << "Point(" << p.getX() << ", " << p.getY() << ") -> " << "Expected: " << (expected ? "true" : "false") << ", Got: " << (result ? "true" : "false") << std::endl;
}

int main()
{
    Point a(0, 0);
	Point b(5, 0);
	Point c(2, 5);

    // Inside cases
	std::cout << "=== Inside Cases ===" << std::endl;
    runTest(a, b, c, Point(2, 2), true);
    runTest(a, b, c, Point(1, 1), true);
    runTest(a, b, c, Point(2, 3), true);
    runTest(a, b, c, Point(3, 2), true);
    runTest(a, b, c, Point(2, 1), true);
    runTest(a, b, c, Point(1.5f, 2.5f), true);
    runTest(a, b, c, Point(2.2f, 2.2f), true);
    runTest(a, b, c, Point(1.8f, 1.8f), true);
    runTest(a, b, c, Point(1, 2), true);
    runTest(a, b, c, Point(3, 1), true);
    
    // Outside cases
	std::cout << "\n=== Outside Cases ===" << std::endl;
    runTest(a, b, c, Point(-1, -1), false);
    runTest(a, b, c, Point(6, 6), false);
    runTest(a, b, c, Point(0, 6), false);
    runTest(a, b, c, Point(5, 5), false);
    runTest(a, b, c, Point(6, 0), false);
    runTest(a, b, c, Point(-2, 2), false);
    runTest(a, b, c, Point(4, -1), false);
    runTest(a, b, c, Point(3, 4), false);
    runTest(a, b, c, Point(2, -1), false);
    runTest(a, b, c, Point(4, 5), false);
    
    // Edge cases
	std::cout << "\n=== Edge Cases ===" << std::endl;
    runTest(a, b, c, Point(2.5f, 0), false);
    runTest(a, b, c, Point(3.5f, 2.5f), false);
    runTest(a, b, c, Point(1, 0), false);
    runTest(a, b, c, Point(4, 0), false);
    
    // Vertex cases
	std::cout << "\n=== Vertex Cases ===" << std::endl;
    runTest(a, b, c, Point(0, 0), false);
    runTest(a, b, c, Point(5, 0), false);
    runTest(a, b, c, Point(2, 5), false);
    
    return 0;
}