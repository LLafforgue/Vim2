/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:47:14 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/25 16:17:26 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "ft_printf.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len < 2)
		return ;
	temp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = temp;
}

void	sa(t_stacks *stacks)
{
	ft_printf("%s\n", __func__);
	stacks->stats->op_calls[SA]++;
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	ft_printf("%s\n", __func__);
	stacks->stats->op_calls[SB]++;
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	ft_printf("%s\n", __func__);
	stacks->stats->op_calls[SS]++;
	swap(stacks->a);
	swap(stacks->b);
}
