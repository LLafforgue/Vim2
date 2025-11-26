/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ascending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:05:23 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/25 18:37:43 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

bool	ft_is_ascending(int *nlist, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (nlist[i] > nlist[i + 1])
			return (false);
		i++;
	}
	return (true);
}
