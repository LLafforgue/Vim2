/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:16:09 by tcillier          #+#    #+#             */
/*   Updated: 2025/10/11 14:25:26 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush-01.h"

int	safe(int tab[4][4], int row, int col, int nb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[row][i] == nb || tab[i][col] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int tab[4][4], int hints[16], int pos)
{
	int	nb;
	int	row;
	int	col;
	int	i;
	t_hint hint;

	if (pos == 16)
	{
		i = 0;
		while (i < 4)
		{
			hint.left = hints[8 + i];
			hint.right = hints[12 + i];
			hint.verif = 1;
			if (!check_row(tab[i], 4, hint) 
			|| !check_row_rev(tab[i], 4, hint))
				return (0);
			hint.up = hints[i];
			hint.down = hints[4 + i];
			if (!check_col(tab, i, 4, hint) 
			|| !check_col_rev(tab, i, 4, hint))
				return (0);
			i++;
		}
		return (1);
	}
	row = pos / 4;
	col = pos % 4;
	nb = 1;
	while (nb < 4)
	{
		if (safe(tab, row, col, nb))
		{
			tab[row][col] = nb;
			hint.left = hints[8 + row];
			hint.right = hints[12 + row];
			hint.verif = 0;
			if (check_row(tab[row], col + 1, hint) 
			&& check_row_rev(tab[row], col + 1, hint))
			{
				hint.up = hints[col];
				hint.down = hints[4 + col];
				hint.verif = 0;
				if (check_col(tab, col, row + 1, hint) 
				&& check_col_rev(tab, col, row + 1, hint) 
				&& solve(tab, hints, pos +1))
					return (1);
			}
			tab[row][col] = 0;
		}
		nb++;
	}
	return (0);
}
