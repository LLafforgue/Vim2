/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:56:52 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/25 17:32:24 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

unsigned int	ft_sum_unsigned(unsigned int values[], size_t n)
{
	size_t			i;
	unsigned int	sum;

	sum = 0;
	i = 0;
	while (i < n)
		sum += values[i++];
	return (sum);
}
