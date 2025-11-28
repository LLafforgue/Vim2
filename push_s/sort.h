/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osasburg <olivier.sasburg@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:04:55 by llafforg          #+#    #+#             */
/*   Updated: 2025/11/28 17:56:48 by osasburg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# define RADIX 3

# include "types.h"
# include "operations.h"

bool			ft_is_ascending(unsigned int *nlist, size_t size);
size_t			ft_search_max(unsigned int *a, size_t size);
size_t			ft_rot_a(t_stacks *stacks, size_t pos);
size_t			ft_rot_b(t_stacks *stacks, size_t pos);
size_t			ft_eject_atob(t_stacks *stacks, size_t pos);
size_t			ft_eject_btoa(t_stacks *stacks, size_t pos);
void			quick_sort(int *values, size_t size);
void			min_extract_sort(t_stacks *stacks);
void			bucket_sort(t_stacks *stacks);
void			radix_sort(t_stacks *stacks);

#endif