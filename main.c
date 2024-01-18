/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:53:55 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/08 15:43:14 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_check(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if ((argc == 2 && argv[1][0] == ' ' && argv[1][1] == '\0') ||
			(argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	arg_check(argc, argv);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&stack_a, argv + 1, argc == 2);
	if (is_sorted(stack_a) == FALSE)
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			three_sort(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	stack_free(&stack_a);
}
