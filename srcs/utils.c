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

int						ft_atoi(const char *str, char *error, int flags)
{
	static unsigned int	value;
	static unsigned int	max;
	static int			sign;

	if (!str)
		return ((*error = 1));
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		sign = -1;
	max = (sign == 1) ? 2147483647 : 2147483648;
	if (!(*str >= '0' && *str <= '9'))
		return ((*error = 1));
	value = 0;
	while (*str && (*str >= '0' && *str <= '9'))
		if (((value = value * 10 + *str++ - '0') > max) &&
			!(ISOVERFLOW(flags)))
			return ((*error = 1));
	if (*str)
		return ((*error = 1));
	return (value * sign);
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

int					ft_getflags(int *ac, char ***av)
{
	int				flags;

	if (!av || !*av || !**av)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	(*av)++;
	flags = 0;
	while (**av)
	{
		if (ft_strncmp("-help", **av))
			flags |= HELP;
		else if (ft_strncmp("-visual", **av))
			flags |= VISUAL;
		else if (ft_strncmp("-color", **av))
			flags |= COLOR;
		else if (ft_strncmp("-overflow", **av))
			flags |= OVERFLOW;
		else if (ft_strncmp("-doubles", **av))
			flags |= DOUBLES;
		else
			return (flags);
		(*av)++;
		(*ac)--;
	}
	return (flags);
}