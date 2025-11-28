/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llafforg <llafforg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:10:07 by osasburg          #+#    #+#             */
/*   Updated: 2025/11/26 16:35:30 by llafforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int error_code, void *ptr, t_stacks *stacks)
{
	write(STDERR_FILENO, "Error\n", 6);
	free(ptr);
	free_stacks(stacks);
	exit(error_code);
}

void	set_strategy(t_args *parsed_args, t_e_strat strategy)
{
	if (parsed_args->strategy != NO_STRATEGY
		&& parsed_args->strategy != strategy)
		error(INCONSISTENT_ARGS_ERROR, NULL, NULL);
	parsed_args->strategy = strategy;
}

void	parse_named_arg(char *named_arg, t_args *args)
{
	if (ft_strncmp(named_arg, "bench", ARG_LEN_MAX) == 0)
		args->bench_mode = true;
	else if (ft_strncmp(named_arg, "simple", ARG_LEN_MAX) == 0)
		set_strategy(args, SIMPLE);
	else if (ft_strncmp(named_arg, "medium", ARG_LEN_MAX) == 0)
		set_strategy(args, MEDIUM);
	else if (ft_strncmp(named_arg, "complex", ARG_LEN_MAX) == 0)
		set_strategy(args, COMPLEX);
	else if (ft_strncmp(named_arg, "adaptive", ARG_LEN_MAX) == 0)
		set_strategy(args, ADAPTIVE);
	else
		error(INVALID_ARG_ERROR, NULL, NULL);
}

void	check_num_arg(char *num, t_args *args)
{
	char	*str_num;

	str_num = ft_itoa(ft_atoi(num));
	if (ft_strncmp(str_num, num, 12))
		error(INVALID_NUM_ERROR, str_num, NULL);
	free(str_num);
	args->nb_ints++;
}

t_args	parse_args(int argc, char **argv)
{
	t_args	args;
	int		i;

	args.strategy = NO_STRATEGY;
	args.bench_mode = false;
	args.nb_ints = 0;
	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			parse_named_arg(argv[i] + 2, &args);
		else
			check_num_arg(argv[i], &args);
		i++;
	}
	if (args.strategy == NO_STRATEGY)
		args.strategy = ADAPTIVE;
	if (args.nb_ints == 0)
		exit(0);
	return (args);
}

char	*get_strat_name(t_e_strat strategy)
{
	if (strategy == SIMPLE)
		return ("O(n²)");
	if (strategy == MEDIUM)
		return ("O(n\xE2\x88\x9An)");
	if (strategy == COMPLEX)
		return ("O(n log(n))");
	return ("?");
}

void	display_bench(t_stats *stats, bool bench_mode)
{
	unsigned int	*ops;

	if (!bench_mode)
		return ;
	ft_printf_err(BENCH " disorder:\t%f%%\n", stats->disorder_perc);
	if (stats->is_adaptive)
		ft_printf_err(BENCH " strategy:\tAdaptive / %s\n",
			get_strat_name(stats->actual_strategy));
	else
		ft_printf_err(BENCH " strategy:\t%s\n",
			get_strat_name(stats->actual_strategy));
	ops = stats->op_calls;
	stats->total_ops = ft_sum_unsigned(ops, OPS_END);
	ft_printf_err(BENCH " total ops:\t%i\n", stats->total_ops);
	ft_printf_err(BENCH " sa: %u\tsb: %u\tss: %u\tpa: %u\tpb: %u\n",
		ops[SA], ops[SB], ops[SS], ops[PA], ops[PB]);
	ft_printf_err(BENCH " ra: %u\trb: %u\trr: %u\trra: %u\trrb: %u\trrr: %u\n",
		ops[RA], ops[RB], ops[RR], ops[RRA], ops[RRB], ops[RRR]);
}

float	compute_disorder_perc(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		pairs;
	int		unordered;

	i = 0;
	pairs = 0;
	unordered = 0;
	while (i < stack->len - 1)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->values[i] > stack->values[j])
				unordered++;
			pairs++;
			j++;
		}
		i++;
	}
	return (100.0f * unordered / pairs);
}

t_e_strat	get_strategy(float disorder_perc)
{
	if (disorder_perc < 20.0f)
		return (SIMPLE);
	if (disorder_perc < 50.0f)
		return (MEDIUM);
	return (COMPLEX);
}

void	reset_op_stats(t_stats *stats)
{
	size_t	i;

	stats->total_ops = 0;
	i = 0;
	while (i < OPS_END)
		stats->op_calls[i++] = 0;
}

void	compute_stats(t_stacks *stacks, t_args *parsed_args, t_stats *stats)
{
	reset_op_stats(stats);
	stats->disorder_perc = compute_disorder_perc(stacks->a);
	stats->is_adaptive = (parsed_args->strategy == ADAPTIVE);
	if (stats->is_adaptive)
		stats->actual_strategy = get_strategy(stats->disorder_perc);
	else
		stats->actual_strategy = parsed_args->strategy;
	stacks->stats = stats;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stats		stats;
	t_args		parsed_args;

	parsed_args = parse_args(argc - 1, argv + 1);
	if (!init_stacks(&stacks, parsed_args.nb_ints))
		error(MALLOC_ERROR, NULL, &stacks);
	fill_stack_a(argc - 1, argv + 1, &stacks);
	compute_stats(&stacks, &parsed_args, &stats);
	algo_simple(&stacks, 0);
	display(stacks);
	display_bench(&stats, parsed_args.bench_mode);
	free_stacks(&stacks);
}
