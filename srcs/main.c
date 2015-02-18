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

void			ft_order(int a, int b, int c)
{
	if (a <= b && b <= c)
		return ;
	else if (a >= b && b <= c && a <= c)
		ft_putstr("sa");
	else if (a <= b && b >= c && a >= c)
		ft_putstr("rra");
	else if (a >= b && b <= c && a >= c)
		ft_putstr("ra");
	else if (a >= b && b >= c && a >= c)
		ft_putstr("ra ra");
	else if (a <= b && b >= c && a <= c)
		ft_putstr("rra sa");
	else
		ft_putstr("Error\n");
}

static int		ft_cases(int ac, char **av)
{
	int			var[3];
	int			pos;

	if (ac == 0)
		return (ft_put_return("Error\n", -1));
	if (ac == 1)
		return (0);
	pos = 0;
	while (pos != ac)
	{
		if (!(ft_isnum(*av)))
			return (ft_put_return("Error\n", -1));
		var[pos++] = ft_atoi(*av++);
	}
	if (ac == 2)
	{
		if (var[0] > var[1])
			return (ft_put_return("ra\n", 0));
		else
			return (ft_put_return("", 0));
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
	ft_putchar(' ');
}

static void		ft_process(t_lst **la, int len)
{
	int			tmp;
	int			pos;

	pos = 0;
	while (len > 3)
	{
		tmp = ft_highest(la);
		if (tmp > pos)
		{
			ft_putstrloop("ra ", tmp - pos);
			pos = tmp;
		}
		else
		{
			ft_putstrloop("rra ", pos - tmp);
			pos = tmp;
		}
		ft_putstr("pb ");
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
			return (ft_put_return("Error\n", -1));
		ft_pushback(&la, ft_atoi(*av++));
		len++;
	}
	ft_process(&la, len);
	ft_putstrloop("pa ", len - 4);
	ft_putstr("pa ");
	if (len - 3 > 3)
		ft_putstr("rra rra rra\n");
	else
	{
		ft_putstrloop("ra ", len - 4);
		ft_putstr("ra\n");
	}
}
