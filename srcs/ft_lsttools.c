/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 02:16:35 by achazal           #+#    #+#             */
/*   Updated: 2015/02/18 02:16:38 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int						ft_order(int a, int b, int c)
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

int						ft_atoi(const char *str, char *error)
{
	static double 		value;
	static double 		max;
	static int			sign;

	if (!str)
		return ((*error = 1));
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		sign = -1;
	max = (sign == 1) ? 2147483647 : 2147483648;
	if (!(*str >= '0' && *str <= '9'))
		return ((*error = 1));
	value = 0;
	while (*str && (*str >= '0' && *str <= '9'))
		if (((value = value * 10 + *str++ - '0') > max))
			return ((*error = 1));
	if (*str)
		return ((*error = 1));
	return (value * sign);
}

int						ft_doubles(t_lst **la)
{
	t_lst				*head;
	t_lst				*ptr;

	if (!la || !*la)
		return (0);
	head = *la;
	while (head)
	{
		ptr = head->ne;
		while (ptr)
		{
			if (head->value == ptr->value)
				return (1);
			ptr = ptr->ne;
		}
		head = head->ne;
	}
	return (0);
}

static	void			ft_get_before_lowest(t_lst **l, t_lst **bl,
											int *pos, int here)
{
	int					i;
	int					value;
	t_lst				*ptr;

	ptr = *l;
	value = ptr->value;
	*bl = NULL;
	i = 0;
	*pos = i;
	while (ptr->ne)
	{
		if (ptr->ne->value < value || (ptr->ne->value == value &&
			(ABS(here - i - 1) < ABS(*pos - here))))
		{
			value = ptr->ne->value;
			*bl = ptr;
			*pos = i + 1;
		}
		ptr = ptr->ne;
		i++;
	}
}

int						ft_lowest(t_lst **l, int here)
{
	t_lst				*before_lowest;
	t_lst				*ptr;
	int					pos;

	ft_get_before_lowest(l, &before_lowest, &pos, here);
	if (before_lowest)
	{
		ptr = before_lowest->ne;
		before_lowest->ne = ptr->ne;
	}
	else
	{
		ptr = *l;
		*l = ptr->ne;
	}
	free(ptr);
	return (pos);
}
