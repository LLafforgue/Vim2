/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:54:38 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/03 17:34:37 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(char *str);
int		ft_isascii(char *str);
int		ft_isdigit(char *str);
int		ft_isprint(char *str);
void	*ft_memset(void *buff, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);
size_t	ft_strlen(char *str);
int		ft_tolower(int c);

#endif 
