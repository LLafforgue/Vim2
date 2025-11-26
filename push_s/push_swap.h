/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:24:27 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/26 11:39:31 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "types.h"
# include "operations.h"
# include "algo.h"
# include "stack_mgmt.h"

# define ARG_LEN_MAX 10
# define BENCH "[bench]"

// error codes
# define INVALID_NUM_ERROR 1
# define DUPLICATE_NUM_ERROR 2
# define INVALID_ARG_ERROR 5
# define INCONSISTENT_ARGS_ERROR 6
# define MALLOC_ERROR 10

unsigned int	ft_sum_unsigned(unsigned int values[], size_t n);

#endif
