/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:48:34 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/09 20:02:00 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/BaseFunctions.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "\033[1;35m=== Base Type Identification Test ===\033[0m\n" << std::endl;

	srand(time(0));

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "\033[1;33m--- Test " << i + 1 << " ---\033[0m" << std::endl;

		Base* base = generate();

		std::cout << "Using pointer: ";
		identify(base);

		std::cout << "Using reference: ";
		identify(*base);

		delete base;

		std::cout << "\033[1;34m----------------------\033[0m\n" << std::endl;
	}

	std::cout << "\033[1;32m=== Test Complete ===\033[0m\n" << std::endl;
	return 0;
}