/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/02/03 16:20:10 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
	int N = 20;

	Zombie *horde = zombieHorde(N, "Zombie");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;
	return (0);
}