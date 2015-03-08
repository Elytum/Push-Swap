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

int						ft_check1(t_lst *head)
{
	int					save1;
	int					save2;
	t_lst				*ptr;

	save1 = head->value;
	save2 = head->ne->value;
	ptr = head->ne->ne;
	if (!(ptr->value < ptr->ne->value) || (save1 < save2) ||
		!(save1 < ptr->value) || !(save2 < ptr->value))
		return (0);
	while (ptr->ne)
	{
		if ((ptr->value < ptr->ne->value) ||
			(save1 < ptr->ne->value) ||
			(save2 < ptr->ne->value))
			return (0);
		ptr = ptr->ne;
	}
	write(1, "sa\n", 3);
	return (1);
}

int						ft_check2(t_lst *head)
{
	int					save1;
	int					save2;
	t_lst				*ptr;

	ptr = head;
	while (ptr->ne->ne)
		ptr = ptr->ne;
	save1 = ptr->value;
	save2 = ptr->ne->value;
	ptr = head;
	if (!(ptr->value < ptr->ne->value) || !(save1 < save2))
		return (0);
	while (ptr->ne->ne->ne)
	{
		if ((ptr->value < ptr->ne->value) ||
			(save1 > ptr->ne->value) ||
			(save2 > ptr->ne->value))
			return (0);
		ptr = ptr->ne;
	}
	write(1, (REV_RU) ? "ra ra sa rra rra\n" : "rra rra sa ra ra\n", 17);
	return (1);
}

int						ft_ordered(t_lst *head, int len)
{
	t_lst		*ptr;

	if (!head)
		return (-1);
	if (ft_check1(head) || ft_check2(head))
		return (1);
	ptr = head;
	while (ptr->ne)
	{
		if (ptr->value > ptr->ne->value)
			return (0);
		ptr = ptr->ne;
	}
	return (1);
	len++;
}
