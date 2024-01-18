/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:31:22 by utente            #+#    #+#             */
/*   Updated: 2023/12/07 12:51:32 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

static t_list	*find_max(t_list *stack)
{
	int		max;
	t_list	*node;

	if (stack == NULL)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

void	three_sort(t_list **stack_a)
{
	t_list	*node;

	node = find_max(*stack_a);
	if (*stack_a == node)
		ra(stack_a);
	else if ((*stack_a)->next == node)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	five_sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		init(*stack_a, *stack_b);
		to_top_a(stack_a, find_min(*stack_a));
		pb(stack_b, stack_a);
	}
}
