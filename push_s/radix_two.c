/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:06:42 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/26 16:16:36 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "types.h"
#include "ft_printf.h"
#include "stack_mgmt.h"

int ft_search_unit_max(int *a, int len, int exp, int mod)
{
	int	i;
	int	pos_m;

	i = 0;
	// ft_printf_err("--exp : %d - mod : %d --\n", exp, mod);
	if (len == 0)
		return (0);
	while (i < len)
	{
		if ((absu(a[i]) / puiss_n(BASE,exp)) % BASE - mod == 0)
		{
			pos_m = i;
			while (i++ < len)
			{
				// ft_printf_err("--max [%d]--\n", a[pos_m]);
				if ((absu(a[i]) / puiss_n(BASE,exp)) % BASE - mod == 0
					&& absu(a[i]) % puiss_n(BASE,exp) > absu(a[pos_m]) % puiss_n(BASE,exp))
					pos_m = i;
			}
			return (pos_m);
		}
		i++;
	}
	return (0);
}

int ft_search_unit_min(int *a, int len, int exp, int mod)
{
	int	i;
	int	pos;

	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if ((absu(a[i]) / puiss_n(BASE,exp)) % BASE - mod == 0)
		{
			pos = i;
			while (i++ < len)
			{
				// ft_printf_err("--max [%d]--\n", a[pos]);
				if ((absu(a[i]) / puiss_n(BASE,exp)) % BASE - mod == 0
					&& absu(a[i]) % puiss_n(BASE,exp) < absu(a[pos]) % puiss_n(BASE,exp))
					pos = i;
			}
			return (pos);
		}
		i++;
	}
	return (0);
}

void ft_radix_even_atob(t_stacks *stacks, int exp)
{
	size_t	i;
	int		mod;
	t_stack	*a;

	i = 0;
	mod = 0;
	a = stacks->a;
	while (mod < BASE && a->len)
	{
		while (a->len && i < a->len)
		{
			if ((absu(a->values[i]) / puiss_n(BASE,exp)) % BASE - mod == 0)
				i = ft_eject_atob(stacks, i);
			else
				i++;
		}
		mod++;
		i = ft_search_unit_min(a->values, a->len, exp, mod);
		i = ft_rot_a(stacks, i);
		// if (ft_sorted(a->values, a->len))
		// 	return ;
	}
}

void ft_radix_odd_btoa(t_stacks *stacks, int exp)
{
	size_t	i;
	t_stack	*b;
	int		mod;

	i = 0;
	mod = BASE - 1;
	b = stacks->b;
	while (mod >= 0 && b->len)
	{
		while (i < b->len)
		{
			if ((absu(b->values[i]) / puiss_n(BASE,exp)) % BASE - mod == 0
				&& b->values[i] > puiss_n(BASE,exp) - 1)
				i = ft_eject_btoa(stacks, i);
			else
				i++;
		}
		mod--;
		i = ft_search_unit_max(b->values, b->len, exp, mod);
		i = ft_rot_b(stacks, i);
	}
	exp = ft_search_max(b->values, b->len);
	ft_rot_b(stacks, exp);
}

void radix(t_stacks *stacks)
{
	int		exp;
	int		exp_max;
	t_stack	*a;
	t_stack	*b;

	exp = 0;
	a = stacks->a;
	b = stacks->b;
	exp_max = ft_exp_max(a->values, a->len);
	while (!ft_sorted(a->values, a->len) && exp <= exp_max)
	{
		if (exp % 2 == 0)
			ft_radix_even_atob(stacks, exp);
		else
			ft_radix_odd_btoa(stacks, exp);
		exp++;
	}
	exp = ft_search_max(b->values, b->len);
	ft_rot_b(stacks, exp);
	while (b->len)
		pa(stacks);
}

/*
#include <stdio.h>
int main()
{
   int  A[3] = {0, 5, 10};

   printf("%d\n",ft_sorted(A, 3));
} */