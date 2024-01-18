/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:42:38 by utente            #+#    #+#             */
/*   Updated: 2023/12/06 15:37:50 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	isneg;
	int	i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void	init_stack(t_list **stack_a, char **argv, int argc)
{
	int	num;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (syntax_check(argv[i]))
			error(stack_a, argv, argc);
		num = ft_atoi(argv[i]);
		if (!is_valid(num, argv[i]))
			error(stack_a, argv, argc);
		if (repeat(*stack_a, num))
			error(stack_a, argv, argc);
		append(stack_a, num);
		++i;
	}
	if (argc)
		free_2d(argv);
}
