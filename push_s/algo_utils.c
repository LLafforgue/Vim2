/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:06:38 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/26 15:10:06 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

//fonctions maths
unsigned int	absu(int n)
{
	long	l_n;

	l_n = n;
	if (l_n < 0)
		return ((unsigned)-l_n);
	return ((unsigned) l_n);
}

int	puiss_n(int a, int n)
{
	int	res;

	if (a == 0 || n == 1)
		return (a);
	res = a;
	if (n <= 0)
		return (1);
	if (n > 1)
		return res * puiss_n(a, n - 1);
	return (0);
}

int	ft_exp_max(int *a, int len)
{
	int	max;
	int	exp;

	max = a[ft_search_max(a, len)];
	exp = 0;
	while (max > 0)
	{
		max /= BASE;
		exp++;
	}
	return (exp);
}

//fonctions de comparaison
int	ft_search_min(int *a, int size)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < size)
	{
		while (a[i] > a[pos] && i < size)
			i++;
		if (i == size && a[i - 1] > a[pos])
			return (pos);
		pos = i;
		i++;
	}
	return (pos);
}

int	ft_search_max(int *a, int size)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < size)
	{
		while (a[i] < a[pos] && i < size)
			i++;
		if (i == size && a[i - 1] < a[pos])
			return (pos);
		pos = i;
		i++;
	}
	return (pos);
}

int	ft_sorted(int *a, int len)
{
	int	base;
	int	i;

	i = 0;
	base = a[i] > a[i + 1];
	if (len == 1)
		return (1);
	if (!len)
		return (0);
	while (i < len - 1)
	{
		if (base != (a[i] > a[i + 1]))
			return (0);
		i ++;
	}
	return (1);
}

int	ft_sorted_ra(int *a, int len)
{
	int	base;
	int	i;
	int	j;
	int	n_num;

	if (len == 1)
		return (1);
	if (!len)
		return (0);
	i = ft_search_min(a, len);
	j = (i + 1) % len;
	base = a[i] > a[j];
	n_num = 1;
	while (n_num < len - 1)
	{
		i = (i + 1) % len;
		j = (i + 1) % len;
		if (base != (a[i] > a[j]))
			return (0);
		n_num++;
	}
	return (1);
}

//fonctions d'operation de tri
size_t	ft_eject_atob(t_stacks *stacks, size_t pos)
{
	size_t	i;

	i = ft_rot_a(stacks, pos);
	pb(stacks);
	return (i);
}

size_t	ft_eject_btoa(t_stacks *stacks, size_t pos)
{
	size_t	i;
	
	i = ft_rot_b(stacks, pos);
	pa(stacks);
	return (i);
}

	//rot, eject puis reviens au depart
void	ft_eject_btoa_init(t_stacks *stacks, size_t pos)
{
	ft_rot_b(stacks, pos);
	pa(stacks);
	if (stacks->b->len)
		ft_rot_b(stacks, stacks->b->len - pos);
}

void	ft_eject_atob_init(t_stacks *stacks, size_t pos)
{
	ft_rot_a(stacks, pos);
	pb(stacks);
	if (stacks->a->len)
		ft_rot_a(stacks, stacks->a->len - pos);
}

size_t	ft_rot_a(t_stacks *stacks, size_t pos)
{
	t_stack	*a;
	
	if (pos == 0)
		return (0);
	a = stacks->a;
	if (pos <= a->len / 2)
		while (pos--)
			ra(stacks);
	else
		while(pos++ % a->len)
			rra(stacks);
	return(0);
}

size_t	ft_rot_b(t_stacks *stacks, size_t pos)
{
	t_stack	*b;
	
	if (pos == 0)
		return (0);
	b = stacks->b;
	if (pos <= b->len / 2)
		while (pos--)
			rb(stacks);
	else
		while(pos++ % b->len)
			rrb(stacks);
	return(0);
}
/* 
#include <stdio.h>
int main()
{
	int A[5] = {1, 2, 3, -1, -2};
	
	printf("%d\n", puiss_n(2, 4));
	printf("%d\n", ft_sorted_ra(A, 5));
} 
*/