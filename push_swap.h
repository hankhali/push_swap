/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:24:52 by hankhali          #+#    #+#             */
/*   Updated: 2024/02/19 21:30:21 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
}						t_stack_node;

int						error_syntax(char *str);
int						ft_atol(const char *str);
int						error_duplicate(t_stack_node *a, int n);
void					free_errors(t_stack_node **a);
void					free_stack(t_stack_node **stack);
void					append_node(t_stack_node **stack, int n);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					push(t_stack_node **dst, t_stack_node **src);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					rev_rotate(t_stack_node **stack);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					rotate(t_stack_node **stack);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					swap(t_stack_node **head);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					init_stack_a(t_stack_node **a, char **av);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					move_a_to_b(t_stack_node **a, t_stack_node **b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					current_index(t_stack_node *stack);
void					min_on_top(t_stack_node **a);
void					set_target_a(t_stack_node *a, t_stack_node *b);
void					cost_analysis_a(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *stack);
void					set_target_b(t_stack_node *a, t_stack_node *b);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
int						count_words(char *s, char c);
char					*get_next_word(char *s, char c);
char					**split(char *s, char c);
int						ft_strlen(char *str);
int						ft_isdigit(int c);
void					handle_multiple_strings(int ac, char **av);
int						ft_strlen(char *str);
char					*ft_strcat(char *dest, const char *src);
int						is_whitespace_string(const char *str);

#endif