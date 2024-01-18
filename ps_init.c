/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:02:48 by utente            #+#    #+#             */
/*   Updated: 2023/12/07 11:49:17 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_posmed(t_list *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (stack == NULL)
		return ;
	mid = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= mid)
			stack->median = TRUE;
		else
			stack->median = FALSE;
		stack = stack->next;
		++i;
	}
}

static void	set_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	t_list	*target;
	int		best;

	while (stack_b)
	{
		best = INT_MAX;
		temp = stack_a;
		while (temp)
		{
			if (temp->content > stack_b->content && temp->content < best)
			{
				best = temp->content;
				target = temp;
			}
			temp = temp->next;
		}
		if (best == INT_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	set_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->pos;
		if (!(stack_b->median))
			stack_b->cost = len_b - (stack_b->pos);
		if (stack_b->target->median)
			stack_b->cost += stack_b->target->pos;
		else
			stack_b->cost += len_a - (stack_b->target->pos);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_list *stack_b)
{
	int		best;
	t_list	*node;

	if (stack_b == NULL)
		return ;
	best = INT_MAX;
	while (stack_b)
	{
		if (stack_b->cost < best)
		{
			best = stack_b->cost;
			node = stack_b;
		}
		stack_b = stack_b->next;
	}
	node->cheapest = TRUE;
}

void	init(t_list *stack_a, t_list *stack_b)
{
	set_posmed(stack_a);
	set_posmed(stack_b);
	set_target(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_b);
}
