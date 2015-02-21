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

int						ft_ordered(t_lst *head)
{
	t_lst				*ptr;

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

int						ft_doubles(t_lst **la)
{
	t_lst				*head;
	t_lst				*ptr;

	if (!la || !*la)
		return (0);
	head = *la;
	while (head)
	{
		ptr = head->next;
		while (ptr)
		{
			if (head->value == ptr->value)
				return (1);
			ptr = ptr->next;
		}
		head = head->next;
	}
	return (0);
}

static	void		ft_get_before_lowest(t_lst **l, t_lst **bl, int *pos, int here)
{
	static int		i;
	static int		value;
	static t_lst	*ptr;

	ptr = *l;
	value = ptr->value;
	*bl = NULL;
	i = 0;
	*pos = i;
	while (ptr->next)
	{
		if (ptr->next->value < value || (ptr->next->value == value &&
			(ABS(here - i - 1) < ABS(*pos - here))))
		{
			value = ptr->next->value;
			*bl = ptr;
			*pos = i + 1;
		}
		ptr = ptr->next;
		i++;
	}
}

int					ft_lowest(t_lst **l, int here)
{
	static t_lst	*before_lowest;
	static t_lst	*ptr;
	static int		pos;

	ft_get_before_lowest(l, &before_lowest, &pos, here);
	if (before_lowest)
	{
		ptr = before_lowest->next;
		before_lowest->next = ptr->next;
	}
	else
	{
		ptr = *l;
		*l = ptr->next;
	}
	free(ptr);
	return (pos);
}
