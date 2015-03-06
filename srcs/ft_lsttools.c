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
#include <stdio.h>

int					ft_order(int a, int b, int c)
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

int					ft_ordered(t_lst *head)
{
	t_lst			*ptr;

	if (!head)
		return (-1);
	ptr = head;
	while (ptr->ne)
	{
		if (ptr->value < ptr->ne->value)
			return (0);
		ptr = ptr->ne;
	}
	return (1);
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

int					ft_lowest(t_lst **la, t_lst **lb, int here)
{
	static t_lst	*before_lowest;
	static t_lst	*ptr;
	static int		pos;

	ft_get_before_lowest(la, &before_lowest, &pos, here);
	if (before_lowest)
	{
		ptr = before_lowest->ne;
		before_lowest->ne = ptr->ne;
	}
	else
	{
		ptr = *la;
		*la = ptr->ne;
	}
	ptr->ne = NULL;
	if (lb && !*lb)
		*lb = ptr;
	else if (lb)
	{
		ptr->ne = *lb;
		*lb = ptr;
	}
	return (pos);
}
