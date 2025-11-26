/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:06:33 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/26 17:15:04 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	simple_sort(t_stacks *stacks)
{
	size_t	pos;
	size_t	total_len;

	total_len = stacks->a->len;
	while (!ft_is_ascending(stacks->a->values, stacks->a->len))
	{
		pos = ft_search_min(stacks->a->values, stacks->a->len);
		ft_eject_atob(stacks, pos);
		if (ft_sorted_ra(stacks->a->values, stacks->a->len))
			ft_rot_a(stacks,ft_search_min(stacks->a->values, stacks->a->len));
	}
	while (stacks->a->len < total_len)
		pa(stacks);
}
