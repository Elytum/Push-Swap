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
#include <stdlib.h>

static int			ft_cases(int ac, char **av)
{
	int				var[3];
	char			error;

	error = 0;
	if (ac <= 1)
		return ((ac < 0 ||
		(ft_atoi(*av++, &error) && error) ? write(1, "Error\n", 6) : 0));
	if (((var[0] = ft_atoi(*av++, &error)) && error) ||
		((var[1] = ft_atoi(*av++, &error)) && error) ||
		var[0] == var[1])
		return (write(1, "Error\n", 6));
	if (ac == 2)
		return (((var[0] > var[1]) == REV_RU) ? write(1, "sa\n", 3) : 0);
	if (((var[2] = ft_atoi(*av++, &error)) && error) ||
		var[0] == var[2] || var[1] == var[2])
		return (write(1, "Error\n", 6));
	if (!REV_RU)
		return ((ft_order(var[2], var[1], var[0])) ? write(1, "\n", 1) : 0);
	return ((ft_order(var[0], var[1], var[2])) ? write(1, "\n", 1) : 0);
}

static void			ft_porcess_output(int pos, int tmp, int len)
{
	static int		a;
	static int		b;
	static char		*str;

	if (tmp > pos)
	{
		a = tmp - pos;
		b = len - tmp + pos;
		str = (a <= b) ? "ra " : "rra ";
	}
	else
	{
		a = pos - tmp;
		b = len - pos + tmp;
		str = (a <= b) ? "rra " : "ra ";
	}
	a = (a <= b) ? a : b;
	b = (*(str + 1) == 'r') ? 4 : 3;
	while (a--)
		write(1, str, b);
}

static void			ft_process(t_lst **la, int len)
{
	int				tmp;
	int				pos;

	pos = 0;
	tmp = 0;
	while (len > 3)
	{
		tmp = ft_lowest(la, pos);
		ft_porcess_output(pos, tmp, len--);
		pos = tmp;
		write(1, "pb ", 3);
		if (pos >= len)
			pos -= len;
	}
	if (len != 3 || tmp > 3)
		return ;
	if (pos == 0)
		tmp = ft_order((*la)->value, (*la)->ne->value, (*la)->ne->ne->value);
	else if (pos == 1)
		tmp = ft_order((*la)->ne->value, (*la)->ne->ne->value, (*la)->value);
	else
		tmp = ft_order((*la)->ne->ne->value, (*la)->value, (*la)->ne->value);
	if (tmp)
		write (1, " ", 1);
}

static char			ft_pushback(t_lst **head, int v, char quit)
{
	static t_lst	*tmp;
	static t_lst	*ptr;

	if (quit || !(tmp = (t_lst *)malloc(sizeof(t_lst))))
		return (quit);
	tmp->value = v;
	tmp->ne = NULL;
	if (!head)
		return (1);
	else if (!*head)
		*head = tmp;
	else if (REV_RU)
	{
		ptr = *head;
		while (ptr->ne)
			ptr = ptr->ne;
		ptr->ne = tmp;
	}
	else
	{
		tmp->ne = *head;
		*head = tmp;
	}
	return (0);
}

int					main(int ac, char **av)
{
	t_lst			*la;
	int				len;
	char			v;

	av++;
	la = NULL;
	len = 0;
	if (ac <= 4)
		return (ft_cases(ac - 1, av));
	while (*av && ++len)
		if (ft_pushback(&la, ft_atoi(*av++, &v), v))
			return (write(1, "Error\n", 6));
	if (ft_doubles(&la) || (v = ft_ordered(la, len)) == -1 || v == 1)
		return ((v == 1) ? 0 : write(1, "Error\n", 6));
	if (v == 1)
		return (0);
	ft_process(&la, len);
	len -= 4;
	while (len--)
		write(1, "pa ", 3);
	write(1, "pa\n", 3);
	return (0);
}
