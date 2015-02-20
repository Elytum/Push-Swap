/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 02:38:35 by achazal           #+#    #+#             */
/*   Updated: 2015/02/18 02:38:40 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int				ft_order(int a, int b, int c)
{
	if (a <= b && b <= c)
		return (0);
	else if (a >= b && b <= c && a <= c)
		return (write(1, "sa", 2));
	else if (a <= b && b >= c && a >= c)
		return (write(1, "rra", 3));
	else if (a >= b && b <= c && a >= c)
		return (write(1, "ra", 2));
	else if (a >= b && b >= c && a >= c)
		return (write(1, "ra sa", 5));
	else if (a <= b && b >= c && a <= c)
		return (write(1, "rra sa", 6));
	return (write(1, "Error", 5));
}

int				ft_ordered(t_lst *head)
{
	t_lst		*ptr;

	if (!head)
		return (-1);
	ptr = head;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int				ft_isnum(char *str)
{
	char		*ptr;

	ptr = str;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr)
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (0);
		ptr++;
	}
	return (1);
}

void			ft_putstrloop(char *str, int times, int len)
{
	while (times--)
		write(1, str, len);
}

int				ft_atoi(const char *str)
{
	int	value;
	int	sign;

	sign = 1;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (str[0] == '+')
		str++;
	else if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	value = 0;
	while (str[0] && (*str >= '0' && *str <= '9'))
	{
		value = value * 10 + str[0] - '0';
		str++;
	}
	return (value * sign);
}
