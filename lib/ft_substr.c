/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:38:26 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/05 14:38:30 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	char	*temp;

	while (start-- && *s)
		s++;
	if (*s && len != 0)
	{
		copy = malloc((len + 1) * sizeof(char));
		if (!copy)
			return (NULL);
		temp = copy;
		while (len && *s)
		{
			*copy++ = *s++;
			len--;
		}
		*copy = '\0';
		return (temp);
	}
	copy = malloc(sizeof(char));
	if (!copy)
		return (NULL);
	*copy = '\0';
	return (copy);
}

// #include <stdio.h>
// int main(void)
// {
// 	char * s = ft_substr("tripouille", 0, 42000);

// 	printf("%s\n", s);
// 	free(s);
// }

