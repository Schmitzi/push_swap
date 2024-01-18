/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:42:44 by utente            #+#    #+#             */
/*   Updated: 2023/12/07 14:09:20 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FALSE 0
# define TRUE 1

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				pos;
	int				index;
	int				cost;
	int				median;
	int				cheapest;
	int				init;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

//	 Handle input
char			**ft_split(char *str, char separator);

//*** Handle errors-free ***
void			free_2d(char **argv);
void			error(t_list **stack, char **argv, int argc);
void			stack_free(t_list **stack);
int				repeat(t_list *stack, int num);
int				syntax_check(char *str);
void			ft_putendl_fd(char *s, int fd);
int				is_valid(int num, char *argv);
char			*ft_itoa(int nbr);

//*** Stack creation ***
int				ft_atoi(const char *str);
int				ft_strcmp(char *s1, char *s2);
void			init_stack(t_list **stack_a, char **argv, int argc);
void			init(t_list *stack_a, t_list *stack_b);
void			set_posmed(t_list *stack);
void			set_cost(t_list *a, t_list *b);
void			set_cheapest(t_list *b);

//*** linked list utils ***
void			append(t_list **stack, int num);
t_list			*find_last(t_list *node);
t_list			*find_min(t_list *stack);
t_list			*find_cheap(t_list *stack);
int				is_sorted(t_list *stack);
int				ft_lstsize(t_list *stack);
void			to_top_a(t_list **stack, t_list *top);
void			to_top_b(t_list **stack, t_list *top);

//*** Algorithms ***
void			three_sort(t_list **stack_a);
void			five_sort(t_list **stack_a, t_list **stack_b);
void			push_swap(t_list **stack_a, t_list **stack_b);

//*** Commands ***
void			sa(t_list **stack_a);
void			sb(t_list **stack_b);
void			ss(t_list **stack_a, t_list **stack_b);
void			ra(t_list **stack_a);
void			rb(t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b);
void			rra(t_list **stack_a);
void			rrb(t_list **stack_b);
void			rrr(t_list **stack_a, t_list **stack_b);
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_b, t_list **stack_a);
void			rotate_stacks(t_list **stack_a, t_list **stack_b,
					t_list *cheap_node);
void			rev_rotate_stacks(t_list **stack_a, t_list **stack_b,
					t_list *cheap_node);

#endif
