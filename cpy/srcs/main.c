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

static int		ft_cases(int ac, char **av)
{
	int			var[3];
	int			pos;
	char		error;

	error = 0;
	if (ac == 0)
		return (write(1, "Error\n", 6));
	if (ac == 1)
		return ((!(ft_isnum(*av))) ? write(1, "Error\n", 6) : 0);
	pos = 0;
	while (pos != ac)
	{
		var[pos++] = ft_atoi(*av++, &error);
		if (!(ft_isnum(*av)))
			return (write(1, "Error\n", 6));
		if (error)
			return (write(1, "Error\n", 6));
	}
	if (ac == 2)
	{
		if (var[0] > var[1])
			return (write(1, "ra\n", 3));
		else
			return (0);
	}
	if (ft_order(var[0], var[1], var[2]))
		write(1, "\n", 1);
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
	if (ft_order(var[0], var[1], var[2]))
		write (1, " ", 1);
}

static void		ft_porcess_output(int pos, int tmp, int len)
{
	static int	a;
	static int	b;

	if (tmp > pos)
	{
		a = tmp - pos;
		b = len - tmp + pos;
		if (a < b)
			ft_putstrloop("ra ", a, 3);
		else
			ft_putstrloop("rra ", b, 4);
	}
	else
	{
		a = pos - tmp;
		b = len - pos + tmp;
		if (a < b)
			ft_putstrloop("rra ", a, 4);
		else
			ft_putstrloop("ra ", b, 3);
	}
}

static void		ft_process(t_lst **la, int len)
{
	int			tmp;
	int			pos;

	pos = 0;
	while (len > 3)
	{
		tmp = ft_lowest(la, pos);
		ft_porcess_output(pos, tmp, len);
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
	char		v;

	av++;
	la = NULL;
	len = 0;
	v = 0;
	if (ac <= 4)
		return (ft_cases(ac - 1, av));
	while (*av)
	{
		if (!(ft_isnum(*av)))
			return (write(1, "Error\n", 6));
		if (ft_pushback(&la, ft_atoi(*av++, &v), v))
			return (write(1, "Error\n", 6));
		len++;
	}
	if (ft_doubles(&la) || (v = ft_ordered(la)) == -1 || v == 1)
		return ((v == 1) ? 0 : write(1, "Error\n", 6));
	ft_process(&la, len);
	ft_putstrloop("pa ", len - 4, 3);
	return (write(1, "pa\n", 3));
}
