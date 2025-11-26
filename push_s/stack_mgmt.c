/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:06:25 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/25 11:11:14 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_mgmt.h"
#include "libft.h"
#include "ft_printf.h"

bool	init_stacks(t_stacks *stacks, size_t size)
{
	stacks->max_size = size;
	stacks->a = malloc(sizeof(t_stack));
	stacks->b = malloc(sizeof(t_stack));
	if (stacks->a == NULL || stacks->b == NULL)
		return (false);
	stacks->a->len = 0;
	stacks->a->max_size = size;
	stacks->a->values = malloc(size * sizeof(int));
	stacks->b->len = 0;
	stacks->b->max_size = size;
	stacks->b->values = malloc(size * sizeof(int));
	return (stacks->a->values && stacks->b->values);
}

void	display(t_stacks stacks)
{
	size_t	i;

	ft_printf_err("A:\n");
	i = 0;
	while (i < stacks.a->len)
		ft_printf_err("[%i]\n", stacks.a->values[i++]);
	ft_printf_err("B:\n");
	i = 0;
	while (i < stacks.b->len)
		ft_printf_err("[%i]\n", stacks.b->values[i++]);
}

void	fill_stack_a(int count, char **args, t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (args[i][0] && args[i][1] != '-')
			stacks->a->values[stacks->a->len++] = ft_atoi(args[i]);
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
		{
			free(stacks->a->values);
			free(stacks->a);
		}
		if (stacks->b)
		{
			free(stacks->b->values);
			free(stacks->b);
		}
	}
}
