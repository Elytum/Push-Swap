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

int				ft_abs(int v)
{
	return ((v < 0) ? -v : v);
}

int				ft_isnum(char *str)
{
	char		*ptr;

	ptr = str;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr)
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (0);
		ptr++;
	}
	return (1);
}

void			ft_putstrloop(char *str, int times)
{
	char		*ptr;
	int			len;

	ptr = str;
	while (*ptr)
		ptr++;
	len = ptr - str;
	while (times--)
		write(1, str, len);
}

int				ft_atoi(const char *str)
{
	int	value;
	int	sign;

	sign = 1;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (str[0] == '+')
		str++;
	else if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	value = 0;
	while (str[0] && (*str >= '0' && *str <= '9'))
	{
		value = value * 10 + str[0] - '0';
		str++;
	}
	return (value * sign);
}
