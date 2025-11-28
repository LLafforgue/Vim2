#include "algo.h"
#include "ft_printf.h"
#include "push_swap.h"

void	algo_a(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (a->len - 1)
	{
		if (a->values[0] > a->values[1])
		{
			sa(stacks);
			pb(stacks);
			if (b->len && b->values[0]<b->values[1])
				sb(stacks);
			return (algo_a(stacks));
		}
		else
		{
			pb(stacks);
			if (b->len && b->values[0]<b->values[1])
				sb(stacks);
			return (algo_a(stacks));
		}
	}
	return ;
}

void	algo_b(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (b->len - 1)
	{
		if (b->values[0] < b->values[1])
		{
			sb(stacks);
			pa(stacks);
			if (a->len && a->values[0]>a->values[1])
				sa(stacks);
			return (algo_b(stacks));
		}
		else
		{
			pa(stacks);
			if (a->len && a->values[0]>a->values[1])
				sa(stacks);
			return (algo_b(stacks));
		}
	}
	return ;
}

void	algo_simple(t_stacks *stacks, int rank)
{
	if (ft_sorted_ra(stacks->a->values, stacks->a->len) 
			&& ft_sorted(stacks->b->values, stacks->b->len))
	{
		ft_rot_a(stacks, ft_search_min(stacks->a->values, stacks->a->len));
		while (stacks->b->len)
			pa(stacks);
		return ;
	}
	if (rank % 2 == 0)
		algo_a(stacks);
	else
		algo_b(stacks);
	return (algo_simple(stacks, rank + 1));
}