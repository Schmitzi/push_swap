/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:57:22 by utente            #+#    #+#             */
/*   Updated: 2023/12/08 15:13:15 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(int num, char *argv)
{
	char	*temp;

	temp = ft_itoa(num);
	if (!temp)
		return (FALSE);
	if (!ft_strcmp(temp, argv))
	{
		free(temp);
		return (TRUE);
	}
	free(temp);
	return (FALSE);
}

void	error(t_list **stack, char **argv, int argc)
{
	stack_free(stack);
	if (argc)
		free_2d(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	syntax_check(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	repeat(t_list *stack, int num)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
