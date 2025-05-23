/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:50:22 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/12 21:15:35 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <algorithm>
#include <iterator>
#include <stdexcept>


template <typename T>
int easyfind(const T& container, int needle)
{
	typename T::const_iterator iter = std::find(container.begin(), container.end(), needle);
	if (iter == container.end())
		throw std::runtime_error("could not find an occurence of the parameter in the container");
	return (std::distance(container.begin(), iter));
}