/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:59:11 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 23:12:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename A, typename F>
void iter(A *array, size_t length, F function)
{
	for (size_t i = 0; i < length; ++i)
	{
		function(array[i]);
	}
}

#endif