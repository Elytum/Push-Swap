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

static	t_lst	*ft_newlst(int v)
{
	t_lst		*ptr;

	if (!(ptr = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ptr->value = v;
	ptr->next = NULL;
	return (ptr);
}

void			ft_pushback(t_lst **head, int v)
{
	t_lst		*tmp;
	t_lst		*ptr;

	tmp = ft_newlst(v);
	if (!head)
		return ;
	else if (!*head)
		*head = tmp;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
	}
}

static	void	ft_get_before_lowest(t_lst **l, t_lst **bl, int *pos)
{
	int			i;
	int			value;
	t_lst		*ptr;

	ptr = *l;
	value = ptr->value;
	*bl = NULL;
	i = 0;
	*pos = i;
	while (ptr->next)
	{
		if (ptr->next->value < value)
		{
			value = ptr->next->value;
			*bl = ptr;
			*pos = i + 1;
		}
		ptr = ptr->next;
		i++;
	}
}

int				ft_lowest(t_lst **l)
{
	t_lst		*before_lowest;
	t_lst		*ptr;
	int			pos;

	ft_get_before_lowest(l, &before_lowest, &pos);
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
