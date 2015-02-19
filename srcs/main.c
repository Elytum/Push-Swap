/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 02:14:06 by achazal           #+#    #+#             */
/*   Updated: 2015/02/18 02:14:08 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void		ft_order(int a, int b, int c)
{
	if (a <= b && b <= c)
		return ;
	else if (a >= b && b <= c && a <= c)
		write(1, "sa", 2);
	else if (a <= b && b >= c && a >= c)
		write(1, "rra", 3);
	else if (a >= b && b <= c && a >= c)
		write(1, "ra", 2);
	else if (a >= b && b >= c && a >= c)
		write(1, "ra sa", 5);
	else if (a <= b && b >= c && a <= c)
		write(1, "rra sa", 6);
	else
		write(1, "Error\n", 6);
}

static int		ft_cases(int ac, char **av)
{
	int			var[3];
	int			pos;

	if (ac == 0)
		return (write(1, "Error\n", 6));
	if (ac == 1)
		return (0);
	pos = 0;
	while (pos != ac)
	{
		if (!(ft_isnum(*av)))
			return (write(1, "Error\n", 6));
		var[pos++] = ft_atoi(*av++);
	}
	if (ac == 2)
	{
		if (var[0] > var[1])
			return (write(1, "ra\n", 3));
		else
			return (0);
	}
	ft_order(var[0], var[1], var[2]);
	return (1);
}

static void		ft_almost_finish(t_lst **la, int pos)
{
	int			var[3];

	if (pos == 0)
	{
		var[0] = (*la)->value;
		var[1] = (*la)->next->value;
		var[2] = (*la)->next->next->value;
	}
	else if (pos == 1)
	{
		var[0] = (*la)->next->value;
		var[1] = (*la)->next->next->value;
		var[2] = (*la)->value;
	}
	else
	{
		var[0] = (*la)->next->next->value;
		var[1] = (*la)->value;
		var[2] = (*la)->next->value;
	}
	ft_order(var[0], var[1], var[2]);
	write(1, " ", 1);
}

static void		ft_process(t_lst **la, int len, int a, int b)
{
	int			tmp;
	int			pos;

	pos = 0;
	while (len > 3)
	{
		tmp = ft_lowest(la, pos);
		if (tmp > pos)
			if ((a = (tmp - pos)) < (b = (len - tmp + pos)))
				ft_putstrloop("ra ", a);
			else
				ft_putstrloop("rra ", b);
		else
			if ((a = (pos - tmp)) < (b = (len - pos + tmp)))
				ft_putstrloop("rra ", a);
			else
				ft_putstrloop("ra ", b);
		pos = tmp;
		write(1, "pb ", 3);
		len--;
		if (pos >= len)
			pos -= len;
	}
	if (len == 3)
		ft_almost_finish(la, pos);
}

int				main(int ac, char **av)
{
	t_lst		*la;
	int			len;

	av++;
	la = NULL;
	len = 0;
	if (ac <= 4)
		return (ft_cases(ac - 1, av));
	while (*av)
	{
		if (!(ft_isnum(*av)))
			return (write(1, "Error\n", 6));
		ft_pushback(&la, ft_atoi(*av++));
		len++;
	}
	ft_process(&la, len, 0, 0);
	ft_putstrloop("pa ", len - 4);
	write(1, "pa", 2);
	return (0);
}
