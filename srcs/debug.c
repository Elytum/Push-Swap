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

#include <unistd.h>
#include <stdio.h>

void				ft_testflags(int flags)
{
	dprintf(1, "Flag = %i\n", flags);
	if (ISHELP(flags))
		write(1, "Help\n", 5);
	if (ISVISUAL(flags))
		write(1, "Visual\n", 7);
	if (ISCOLOR(flags))
		write(1, "Color\n", 6);
	if (ISOVERFLOW(flags))
		write(1, "Overflow\n", 9);
	if (ISDOUBLES(flags))
		write(1, "Doubles\n", 8);
}

void				ft_testav(int ac, char **av)
{
	char			**ptr;

	ptr = av;
	dprintf(1, "ac = %i, av : ", ac);
	while (*ptr)
		dprintf(1, "\"%s\" ", *ptr++);
	write(1, "\n", 1);
}

void				ft_putnbr(int v)
{
	char			c;

	if (v == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (v < 0)
	{
		v *= -1;
		write(1, "-", 1);
	}
	if (v >= 10)
	{
		ft_putnbr(v / 10);
		c = v % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = v + '0';
		write(1, &c, 1);
	}
}

void				ft_putlst(t_lst *l)
{
	t_lst			*ptr;

	if (!l)
	{
		write(1, "ERROR\n", 6);
		return ;
	}
	write(1, "{ ", 2);
	ptr = l;
	while (ptr)
	{
		ft_putnbr(ptr->value);
		(ptr->ne) ? write(1, ", ", 2) : 0;
		ptr = ptr->ne;
	}
	write(1, " }\n", 3);
}

void				ft_putstep(t_lst *la, t_lst *lb, char *move, int flags)
{
	char			*ptr;

	ptr = move;
	while (*ptr)
		ptr++;
	write(1, move, ptr - move);
	write(1, "\n\nla : ", 7);
	ft_putlst(la);
	write(1, "lb : ", 5);
	ft_putlst(lb);
	return ;
	flags++;
}
