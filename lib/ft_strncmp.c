/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:18:22 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/04 16:18:24 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*temp;

	temp = s2;
	while (*s1 && *s2 && n > 0)
	{
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		else
		{
			s1++;
			s2++;
			n--;
		}
	}
	return (0);
}
