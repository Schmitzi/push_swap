/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:53:41 by utente            #+#    #+#             */
/*   Updated: 2023/12/06 10:40:58 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **root)
{
	int	len;

	len = ft_lstsize(*root);
	if (root == NULL || *root == NULL || len == 1)
		return ;
	*root = (*root)->next;
	(*root)->prev->prev = *root;
	(*root)->prev->next = (*root)->next;
	if ((*root)->next)
		(*root)->next->prev = (*root)->prev;
	(*root)->next = (*root)->prev;
	(*root)->prev = NULL;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
