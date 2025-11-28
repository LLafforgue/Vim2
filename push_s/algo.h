/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:04:55 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/26 17:28:06 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# define BASE 10

# include "types.h"
# include "operations.h"

unsigned int	absu(int n);
int				puiss_n(int a, int n);
int				ft_search_min(int *a, int size);
int				ft_search_max(int *a, int size);
int				ft_exp_max(int *a, int len);
int				ft_sorted(int *a, int len);
int				ft_sorted_ra(int *a, int len);
bool			ft_is_ascending(int *nlist, size_t len);
size_t			ft_rot_a(t_stacks *stacks, size_t pos);
size_t			ft_rot_b(t_stacks *stacks, size_t pos);
size_t			ft_eject_atob(t_stacks *stacks, size_t pos);
size_t			ft_eject_btoa(t_stacks *stacks, size_t pos);
void			ft_eject_btoa_init(t_stacks *stacks, size_t pos);
void			ft_eject_atob_init(t_stacks *stacks, size_t pos);
void			simple_sort(t_stacks *stacks);
void			radix(t_stacks *stacks);
void			ft_radix_even_atob(t_stacks *stacks, int exp);
void			ft_radix_odd_btoa(t_stacks *stacks, int exp);
void        	algo_simple(t_stacks *stacks, int rank);

#endif