/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:15:00 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/08 10:02:41 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i++]);
	}
	free(argv - 1);
}

void	stack_free(t_list **stack)
{
	t_list	*temp;
	t_list	*curr;

	if (stack == NULL)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}
