/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:01:38 by hankhali          #+#    #+#             */
/*   Updated: 2024/02/19 21:30:31 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_syntax(char *str_n)
{
	int	sign_count;
	int	digit_count;

	sign_count = 0;
	digit_count = 0;
	if (!str_n || *str_n == '\0')
		return (1);
	while (*str_n != '\0')
	{
		if (*str_n == '+' || *str_n == '-')
		{
			sign_count++;
			if (sign_count > 1 || (*(str_n + 1) < '0' || *(str_n + 1) > '9'))
				return (1);
		}
		else if (*str_n >= '0' && *str_n <= '9')
			digit_count++;
		else
			return (1);
		str_n++;
	}
	if (digit_count == 0)
		return (1);
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(0);
}
