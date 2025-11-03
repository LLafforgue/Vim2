/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:18:38 by tcillier          #+#    #+#             */
/*   Updated: 2025/10/11 14:37:23 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RUSH_01_H
#define RUSH_01_H

typedef struct s_hint
{
	int	left;
	int	right;
	int	up;
	int	down;
	int	verif;
}	t_hint;

int	check_row(int row[4], int len, t_hint hint);
int	check_row_rev(int row[4], int len, t_hint hint);
int	check_col(int tab[4][4], int col, int len, t_hint hint);
int	check_col_rev(int tab[4][4], int col, int len, t_hint hint);
int	safe(int tab[4][4], int row, int col, int nb);
int	solve(int tab[4][4], int hints[16], int pos);
#endif
