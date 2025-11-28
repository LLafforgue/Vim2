/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:06:42 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/28 18:00:49 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "types.h"
#include "stack_mgmt.h"

static unsigned int	ft_exp_max(unsigned int *a, int len)
{
	int				max;
	unsigned int	exp;

	max = a[ft_search_max(a, len)];
	exp = 0;
	while (max > 0)
	{
		max /= RADIX;
		exp++;
	}
	return (exp);
}

static unsigned int	ft_pow(int base, int exp)
{
	unsigned int	res;

	if (base == 0 || exp == 1)
		return (base);
	res = base;
	if (exp <= 0)
		return (1);
	if (exp > 1)
		return (res * ft_pow(base, exp - 1));
	return (0);
}

static int	ft_search_unit_max(unsigned int *a, int len, int nth_digit,
	unsigned int d)
{
	int	i;
	int	pos;
	int	power;

	if (len == 0)
		return (0);
	power = ft_pow(RADIX, nth_digit);
	i = 0;
	while (i < len)
	{
		if ((a[i] / power) % RADIX == d)
		{
			pos = i;
			while (i++ < len)
			{
				if ((a[i] / power) % RADIX == d
					&& a[i] % power > a[pos] % power)
					pos = i;
			}
			return (pos);
		}
		i++;
	}
	return (0);
}

static int	ft_search_unit_min(unsigned int *a, int len, int nth_digit,
	unsigned int d)
{
	int	i;
	int	pos;
	int	power;

	i = 0;
	if (len == 0)
		return (0);
	power = ft_pow(RADIX, nth_digit);
	while (i < len)
	{
		if ((a[i] / power) % RADIX == d)
		{
			pos = i;
			while (i++ < len)
			{
				if ((a[i] / power) % RADIX == d
					&& a[i] % power < a[pos] % power)
					pos = i;
			}
			return (pos);
		}
		i++;
	}
	return (0);
}

static void	ft_radix_even_atob(t_stacks *stacks, int nth_digit)
{
	size_t			i;
	t_stack			*a;
	unsigned int	d;
	int				power;

	power = ft_pow(RADIX, nth_digit);
	d = 0;
	a = stacks->a;
	i = 0;
	while (d < RADIX && a->len)
	{
		while (a->len && i < a->len)
		{
			if ((a->ranks[i] / power) % RADIX == d)
				i = ft_eject_atob(stacks, i);
			else
				i++;
		}
		d++;
		i = ft_search_unit_min(a->ranks, a->len, nth_digit, d);
		i = ft_rot_a(stacks, i);
	}
}

static void	ft_radix_odd_btoa(t_stacks *stacks, int nth_digit)
{
	size_t			i;
	t_stack			*b;
	unsigned int	d;
	unsigned int	power;

	i = 0;
	d = RADIX;
	power = ft_pow(RADIX, nth_digit);
	b = stacks->b;
	while (d > 0 && b->len)
	{
		while (i < b->len)
		{
			if ((b->ranks[i] / power) % RADIX == d - 1
				&& b->ranks[i] > power - 1)
				i = ft_eject_btoa(stacks, i);
			else
				i++;
		}
		d--;
		i = ft_search_unit_max(b->ranks, b->len, nth_digit, d - 1);
		i = ft_rot_b(stacks, i);
	}
	nth_digit = ft_search_max(b->ranks, b->len);
	ft_rot_b(stacks, nth_digit);
}

void	radix_sort(t_stacks *stacks)
{
	int		curr_digit;
	int		max_digits;
	t_stack	*a;
	t_stack	*b;

	curr_digit = 0;
	a = stacks->a;
	b = stacks->b;
	max_digits = ft_exp_max(a->ranks, a->len);
	while (!ft_is_ascending(a->ranks, a->len) && curr_digit <= max_digits)
	{
		if (curr_digit % 2 == 0)
			ft_radix_even_atob(stacks, curr_digit);
		else
			ft_radix_odd_btoa(stacks, curr_digit);
		curr_digit++;
	}
	curr_digit = ft_search_max(b->ranks, b->len);
	ft_rot_b(stacks, curr_digit);
	while (b->len)
		pa(stacks);
}
