/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:53 by mdomnik           #+#    #+#             */
/*   Updated: 2025/01/31 17:11:25 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("Zombie"); //when zombie needs to persist outside of the function
	zombie->announce();
	delete zombie;
	randomChump("Chump"); //when zombie is needed only temporarily
	return (0);
}