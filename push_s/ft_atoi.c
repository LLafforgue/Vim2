/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:50:21 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/21 16:19:15 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == '\f' || c == '\r' || c == '\v'
		|| c == ' ');
}

static const char	*skip_spaces(const char *nptr)
{
	int		i;

	i = 0;
	while (nptr[i])
	{
		if (!ft_isspace(nptr[i]))
			break ;
		i++;
	}
	return (nptr + i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	nptr = skip_spaces(nptr);
	sign = 1;
	result = 0;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i++] - '0');
	}
	return (sign * result);
}
