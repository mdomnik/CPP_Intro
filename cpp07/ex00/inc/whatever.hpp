/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:04:31 by mdomnik           #+#    #+#             */
/*   Updated: 2025/05/11 22:17:20 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &arg1, T &arg2)
{
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
const T& min(const T &arg1, const T &arg2)
{
	return (arg1 < arg2) ? arg1 : arg2;
}

template <typename T>
const T& max(const T &arg1,const T &arg2)
{
	return (arg1 > arg2) ? arg1 : arg2;
}

#endif