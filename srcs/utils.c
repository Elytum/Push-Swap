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

#include <stdio.h>

// int						ft_reversed_ordered(t_lst *head)
// {
// 	t_lst				*ptr;

// 	ptr = head;
// 	while (ptr->ne)
// 	{
// 		if (ptr->value < ptr->ne->value)
// 			return (0);
// 		ptr = ptr->ne;
// 	}
// 	return (1);
// }

// int						ft_check1(t_lst *head)//Comparing head
// {
// 	t_lst				*ptr;
// 	int					save1;
// 	int					save2;

// 	// dprintf(1, "Check1 verif with save1 = %i and save2 = %i\n", head->value, head->ne->value);
// 	if (ft_reversed_ordered(head) ||
// 		head->value < head->ne->value)
// 		return (0);
// 	// dprintf(1, "Check1 IN\n");
// 	save1 = head->value;
// 	save2 = head->ne->value;
// 	ptr = head->ne;
// 	while (ptr->ne->ne)
// 	{
// 		// dprintf(1, "Check 1, save1 = %i, save2 = %i, ptr->value = %i, ptr->ne->value %i\n", save1, save2, ptr->value, ptr->ne->value);
// 		if (((ptr->value > ptr->ne->value) == REV_RU) ||
// 			((save1 > ptr->ne->value) == REV_RU) ||
// 			((save2 > ptr->ne->value) == REV_RU))
// 			return (0);
// 		ptr = ptr->ne;
// 	}
// 	if (REV_RU)
// 		write (1, "sa\n", 3);
// 	else
// 		write (1, "rra rra sa ra ra\n", 17);
// 	// else
// 	return (1);
// }
// 3 1 2 4
/*
rra rra sa ra ra -> SWAP FIRST

				4 3 2 1
					rra rra sa ra ra
				3 2 1 4
					rra rra sa ra ra
				41392 59193 8299 19366
					rra rra sa ra ra
	2 4 3 1
		rra rra sa ra ra
	3 4 2 1
		rra rra sa ra ra
*/

// int						ft_check2(t_lst *head)//Comparing tail
// {
// 	t_lst				*ptr;
// 	int					save1;
// 	int					save2;

// 	ptr = head;
// 	while (ptr->ne->ne)
// 		ptr = ptr->ne;
// 	save1 = ptr->value;
// 	save2 = ptr->ne->value;
// 	// dprintf(1, "Check2 verif with save1 = %i and save2 = %i\n", save1, save2);
// 	if (save1 < save2)
// 		return (0);
// 	// dprintf(1, "Check2 IN\n");
// 	ptr = head;
// 	while (ptr->ne->ne)
// 	{
// 		// dprintf(1, "Check 2, save1 = %i, save2 = %i, ptr->value = %i, ptr->ne->value %i\n", save1, save2, ptr->value, ptr->ne->value);
// 		if (((save1 < ptr->value) == REV_RU) ||
// 			((save2 < ptr->value) == REV_RU) ||
// 			(ptr->value > ptr->ne->value))
// 			return (0);
// 		ptr = ptr->ne;
// 	}
// 	// if (REV_RU)
// 		write (1, "sa\n", 3);
// 	// else
// 		// write (1, "ra ra sa rra rra\n", 17);
// 	return (1);
// }



// void					ft_first_values(t_lst *head, int *a, int *b)
// {
// 	*a = head->value;
// 	*b = head->ne->value;
// }

// void					ft_last_values(t_lst *head, int *a, int *b)
// {
// 	t_lst				*ptr;

// 	ptr = head;
// 	while (ptr->ne->ne)
// 		ptr = ptr->ne;
// 	*a = ptr->value;
// 	*b = ptr->ne->value;
// }

int						ft_check1(t_lst *head)
{
	int					save1;
	int					save2;
	int					inc;
	t_lst				*ptr;

	save1 = head->value;
	save2 = head->ne->value;
	ptr = head->ne->ne;
	inc = (ptr->value < ptr->ne->value);
	if ((save1 < save2) == inc || (save1 < ptr->value) != inc ||
		(save2 < ptr->value) != inc || !inc)
		return (0);
	while (ptr->ne)
	{
		if (((ptr->value < ptr->ne->value) != inc) ||
			((save1 < ptr->ne->value) != inc) ||
			((save2 < ptr->ne->value) != inc))
			return (0);
		ptr = ptr->ne;
	}
	write(1, "sa\n", 3);
	return (1);
}


/*
	NEWTESTS

	43469 48969 25820 6761 / 3 4 2 1
*/


	// ra
// 39969 30659 41685 47175 / 2 1 3 4
// 31522 57315 7395 11842 /  3 4 1 2
// 16910 31220 52809 41802 / 1 2 4 3
// 42739 50773 63402 60618 / 1 2 4 3
// 52957 50415 9396 26529 / 4 3 1 2

	// rra
// 3509 38771 60591 44445 / 1 2 4 3
// 9156 18449 62454 40959 / 1 2 4 3
// 40172 49038 64975 49814 / 1 2 4 3
// 63007 26202 5613 24388 / 4 3 1 2
// 31271 9863 39208 56945 / 2 1 3 4
// 26007 48360 23511 5230 / 3 4 2 1
// 7543 2992 16165 27169 / 2 1 3 4
// 38636 46049 28949 57 / 3 4 2 1

// 38636 46049 28949 57 / 3 4 2 1

int						ft_check2(t_lst *head)
{
	int					save1;
	int					save2;
	int					inc;
	t_lst				*ptr;

	inc = -1;

	ptr = head;
	while (ptr->ne->ne)
		ptr = ptr->ne;
	save1 = ptr->value;
	save2 = ptr->ne->value;\
	ptr = head;
	inc = (ptr->value < ptr->ne->value);
	// dprintf(1, "Checking condition : save1 = %i, save2 = %i, inc = %i, ptr->value = %i, C1 = %i, C2 = %i, C3 = %i\n",
	// 	save1, save2, inc, ptr->value, (save1 < save2) == inc, (save1 < ptr->value) != inc,
	// 	((save2 < ptr->ne->value) != inc));
	if ((save1 < save2) == inc || !inc)
		return (0);
	// dprintf(1, "Check passed\n");
	while (ptr->ne->ne->ne)
	{
		// dprintf(1, "ptr->value = %i, ptr->ne->value = %i, C1 = %i, C2 = %i, C3 = %i\n",
		// 	ptr->value, ptr->ne->value, ((ptr->value < ptr->ne->value) != inc),
		// 	((save1 < ptr->ne->value) != inc), ((save2 < ptr->ne->value) != inc));
		if (((ptr->value < ptr->ne->value) != inc) ||
			((save1 > ptr->ne->value) != inc) ||
			((save2 > ptr->ne->value) != inc))
			return (0);
		ptr = ptr->ne;
	}
	// write(1, "sa\n", 3);
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

// 3 4 2 1