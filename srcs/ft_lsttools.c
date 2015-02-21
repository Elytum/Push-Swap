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
