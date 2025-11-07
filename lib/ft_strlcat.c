/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:09:19 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/04 11:09:37 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_s;
	size_t	len_d;
	char	*temp;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	temp = dst;
	if (len_d == size)
		return (len_d + len_s);
	if (size >= len_d + len_s)
	{
		while (*dst)
			dst++;
		while (*src)
			*dst++ = *src++;
	}
	*dst = '\0';
	return (dst - temp);
}
