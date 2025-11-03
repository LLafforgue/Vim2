/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:31:18 by tcillier          #+#    #+#             */
/*   Updated: 2025/10/11 14:05:16 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-01.h"

int	check_row(int row[4], int len, t_hint hint)
{
	int	i;
	int	nbv;
	int	max;

	i = 0;
	max = 0;
	nbv = 0;
	while (i < len)
	{
		if (row[i] > max)
		{
			max = row[i];
			nbv++;
		}
		i++;
	}
	if (nbv > hint.left)
		return (0);
	if (hint.verif && nbv != hint.left)
		return (0);
	return (1);
}

int	check_row_rev(int row[4], int len, t_hint hint)
{
	int	i;
	int	max;
	int	nbv;

	i = len - 1;
	max = 0;
	nbv = 0;
	while (i >= 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			nbv++;
		}
		i--;
	}
	if (nbv > hint.right)
		return (0);
	if (hint.verif && nbv != hint.right)
		return (0);
	return (1);
}

int	check_col(int tab[4][4], int col, int len, t_hint hint)
{
	int	max;
	int	nbv;
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			nbv++;
		}
		i++;
	}
	if (nbv > hint.up)
		return (0);
	if (hint.verif && nbv != hint.up)
		return (0);
	return (1);
}

int	check_col_rev(int tab[4][4], int col, int len, t_hint hint)
{
	int	max;
	int	nbv;
	int	i;

	i = len -1;
	max = 0;
	nbv = 0;
	while (i >= 0)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			nbv++;
		}
		i--;
	}
	if (nbv > hint.down)
		return (0);
	if (hint.verif && nbv != hint.down)
		return (0);
	return (1);
}
