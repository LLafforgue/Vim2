/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:06:38 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/28 17:57:35 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

bool	ft_is_ascending(unsigned int *numbers, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (numbers[i] > numbers[i + 1])
			return (false);
		i++;
	}
	return (true);
}

size_t	ft_search_max(unsigned int *numbers, size_t size)
{
	size_t	i;
	size_t	pos;

	i = 1;
	pos = 0;
	while (i < size)
	{
		while (numbers[i] < numbers[pos] && i < size)
			i++;
		if (i == size && numbers[i - 1] < numbers[pos])
			return (pos);
		pos = i;
		i++;
	}
	return (pos);
}
