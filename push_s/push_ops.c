/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:51:34 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/25 16:21:15 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "ft_printf.h"
#include "shift_ops.h"

void	push(t_stack *stack, int value)
{
	stack->len++;
	ft_shift_down(stack);
	stack->values[0] = value;
}

int	pop(t_stack *stack)
{
	int	value;

	value = stack->values[0];
	ft_shift_up(stack);
	stack->len--;
	return (value);
}

void	pa(t_stacks *stacks)
{
	ft_printf("%s\n", __func__);
	stacks->stats->op_calls[PA]++;
	if (stacks->b->len)
		push(stacks->a, pop(stacks->b));
}

void	pb(t_stacks *stacks)
{
	ft_printf("%s\n", __func__);
	stacks->stats->op_calls[PB]++;
	if (stacks->a->len)
		push(stacks->b, pop(stacks->a));
}
