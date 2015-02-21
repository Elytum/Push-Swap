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

#include <stdio.h>
static int			ft_cases(int ac, char **av)
{
	int				var[3];
	char			error;

	error = 0;
	if (ac <= 1)
		return ((ac < 0 || (ft_atoi(*av++, &error) && error) ?
							write(1, "Error\n", 6) : 0));
	if (((var[0] = ft_atoi(*av++, &error)) && error) ||
		((var[1] = ft_atoi(*av++, &error)) && error))
		return (write(1, "Error\n", 6));
	if (ac == 2)
		return ((var[0] > var[1]) ? write(1, "sa\n", 3) : 0);
	if (((var[2] = ft_atoi(*av++, &error)) && error))
		return (write(1, "Error\n", 6));
	return ((ft_order(var[0], var[1], var[2])) ? write(1, "\n", 1) : 0);
}

static void			ft_porcess_output(int pos, int tmp, int len)
{
	static int		a;
	static int		b;
	static char 	*str;

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
		tmp = ft_order((*la)->value, (*la)->next->value, (*la)->next->next->value);
	else if (pos == 1)
		tmp = ft_order((*la)->next->value, (*la)->next->next->value, (*la)->value);
	else
		tmp = ft_order((*la)->next->next->value, (*la)->value, (*la)->next->value);
	if (tmp)
		write (1, " ", 1);
}

static char			ft_pushback(t_lst **head, int v, char quit)
{
	static t_lst	*tmp;
	static t_lst	*ptr;

	if (quit)
		return (quit);
	if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
		return (quit);
	tmp->value = v;
	tmp->next = NULL;
	if (!head)
		return (1);
	else if (!*head)
		*head = tmp;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
	}
	return (0);
}

int					ft_strncmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (!*a);
}

void				ft_testflags(int flags)
{
	return ;
	dprintf(1, "Flag = %i\n", flags);
	if (flags & 0b00000001)
		write(1, "HELP\n", 5);
	if (flags & 0b00000010)
		write(1, "V\n", 2);
	if (flags & 0b00000100)
		write(1, "C\n", 2);
	if (flags & 0b00001000)
		write(1, "O\n", 2);
}

int					ft_getflags(int *ac, char ***av)
{
	int				flags;

	if (!av || !*av || !**av)
		return ((write(1, "Error\n", 6) == -42) - 1);
	(*av)++;
	flags = 0;
	while (**av)
	{
		if (ft_strncmp("-help", **av))
			flags |= 0b00000001;
		else if (ft_strncmp("-visual", **av))
			flags |= 1 << 1;
		else if (ft_strncmp("-color", **av))
			flags |= 1 << 2;
		else if (ft_strncmp("-overflow", **av))
			flags |= 1 << 3;
		else
			return (flags);
		(*av)++;
		(*ac)--;
	}
	return (flags);
}

void				ft_testav(int ac, char **av)
{
	char			**ptr;

	// return ;
	ptr = av;
	dprintf(1, "ac = %i, av : ", ac);
	while (*ptr)
		dprintf(1, "\"%s\" ", *ptr++);
	write(1, "\n", 1);
}
int					main(int ac, char **av)
{
	t_lst			*la;
	int				len;
	char			v;

	ft_testflags(ft_getflags(&ac, &av));
	ft_testav(ac, av);
	la = NULL;
	len = 0;
	v = 0;
	if (ac <= 4)
		return (ft_cases(ac - 1, av));
	while (*av && ++len)
		if (ft_pushback(&la, ft_atoi(*av++, &v), v))
			return (write(1, "Error\n", 6));
	if (ft_doubles(&la) || (v = ft_ordered(la)) == -1 || v == 1)
		return ((v == 1) ? 0 : write(1, "Error\n", 6));
	ft_process(&la, len);
	len -= 4;
	while (len--)
		write(1, "pa ", 3);
	return (write(1, "pa\n", 3));
}
