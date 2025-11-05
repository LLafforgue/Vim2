/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:32:47 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/05 15:32:50 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_is_a_set(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim;
	const char	*temp;
	size_t		len;

	temp = s1;
	len = !ft_is_a_set(*s1, set);
	while (*s1++)
		if (*s1 && !ft_is_a_set(*s1, set))
			len++;
	s1 = temp;
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	temp = trim;
	while (*s1)
	{
		if (!ft_is_a_set(*s1, set))
			*trim++ = *s1;
		s1++;
	}
	*trim = '\0';
	return ((char *)temp);
}
/*
#include <stdio.h>
int main(void)
{
	const char	*str = "HelLlo L!L";
	char		*trim = ft_strtrim(str , "loL");

	printf("%s\n", trim);
}
*/