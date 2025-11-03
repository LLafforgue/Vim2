/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:57:39 by tcillier          #+#    #+#             */
/*   Updated: 2025/10/11 15:14:08 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush-01.h"

int	parse_input(char *argv, int hints[16])
{
	int	i;

	i = 0;
	while (*argv && i < 16)
	{
		if (*argv >= '1' && *argv <= '4')
		{
			hints[i] = *argv - '0';
			i++;
		}
		else if (*argv != ' ' && *argv != '\t')
			return (0);
		argv++;
	}
	if (i != 16)
		return (0);
	return (1);
}

void	print_tab(int tab[4][4])
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	tab[4][4];
	int	hints[16];
	int	i;
	int	j;

	if (argc != 2 || !parse_input(argv[1], hints))
	{
		write(1, "WError\n", 6);
			return (0);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	if (solve(tab, hints, 0))
		print_tab(tab);
	else
		write(1, "XError\n", 6);
	return (0);
}
