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

static	t_lst	*ft_newlst(int v)
{
	t_lst		*ptr;

	if (!(ptr = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ptr->value = v;
	ptr->next = NULL;
	ptr->past = NULL;
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
		tmp->past = ptr;
	}
}

static	void	ft_get_before_highest(t_lst **l, t_lst 
										**before_highest, int *pos)
{
	int			i;
	int			value;
	t_lst		*ptr;

	ptr = *l;
	value = ptr->value;
	*before_highest = NULL;
	i = 0;
	*pos = i;
	while (ptr->next)
	{
		if (ptr->next->value > value)
		{
			value = ptr->next->value;
			*before_highest = ptr;
			*pos = i + 1;
		}
		ptr = ptr->next;
		i++;
	}
}

int				ft_highest(t_lst **l)
{
	t_lst		*before_highest;
	t_lst		*ptr;
	int			pos;

	ft_get_before_highest(l, &before_highest, &pos);
	if (before_highest)
	{
		ptr = before_highest->next;
		before_highest->next = ptr->next;
	}
	else
	{
		ptr = *l;
		*l = ptr->next;
	}
	free(ptr);
	return (pos);
}
