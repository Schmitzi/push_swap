/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:27:13 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/06 16:09:46 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_len(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		++i;
	while (num != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
		result[0] = '-';
	else if (nbr == 0)
		result[0] = '0';
	while (nbr != 0)
	{
		--len;
		result[len] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}
