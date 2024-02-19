/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:40:16 by hankhali          #+#    #+#             */
/*   Updated: 2024/02/19 21:29:41 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*concatenate_arguments(int argc, char **argv, size_t *concat_len)
{
	char	*args_concat;
	int		i;

	*concat_len = 1;
	i = 1;
	while (i < argc)
	{
		*concat_len += ft_strlen(argv[i]) + 1;
		i++;
	}
	args_concat = (char *)malloc(*concat_len);
	if (!args_concat)
		return (NULL);
	*args_concat = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strcat(args_concat, argv[i]);
		if (i < argc - 1)
			ft_strcat(args_concat, " ");
		i++;
	}
	return (args_concat);
}

char	**process_arguments(int argc, char **argv)
{
	char	*args_concat;
	char	**processed_args;
	size_t	concat_len;

	concat_len = 0;
	if (argc > 2)
		args_concat = concatenate_arguments(argc, argv, &concat_len);
	else
		args_concat = argv[1];
	processed_args = split(args_concat, ' ');
	if (argc > 2)
		free(args_concat);
	return (processed_args);
}

void	init_and_sort_stacks(t_stack_node **a, t_stack_node **b,
		char **processed_args)
{
	init_stack_a(a, processed_args + 1);
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

void	free_processed_args(char **processed_args)
{
	int	i;

	i = 0;
	while (processed_args[i])
	{
		free(processed_args[i]);
		i++;
	}
	free(processed_args);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**processed_args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && is_whitespace_string(argv[1])))
	{
		free_errors(&a);
		return (0);
	}
	processed_args = process_arguments(argc, argv);
	if (!processed_args)
	{
		free_errors(&a);
		return (0);
	}
	init_and_sort_stacks(&a, &b, processed_args);
	free_processed_args(processed_args);
	free_stack(&a);
	return (0);
}
