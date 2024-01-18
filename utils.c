/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:49:59 by utente            #+#    #+#             */
/*   Updated: 2023/12/07 10:46:05 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	append(t_list **stack, int num)
{
	t_list	*node;
	t_list	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return ;
	node->cheapest = 0;
	node->next = NULL;
	node->content = num;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->prev = last;
	}
}

t_list	*find_min(t_list *stack)
{
	int		min;
	t_list	*node;

	if (stack == NULL)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_list	*find_cheap(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (i);
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}
