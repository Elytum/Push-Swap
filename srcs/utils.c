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

int						ft_atoi(const char *str, char *error)
{
	static unsigned int	value;
	static int			sign;

	if (!str)
		return ((*error = 1));
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		sign = -1;
	if (!(*str >= '0' && *str <= '9'))
		return ((*error = 1));
	value = 0;
	while (str[0] && (*str >= '0' && *str <= '9'))
		if ((value = value * 10 + *str++ - '0') > 2147483647)
			return ((*error = 1));
	if (*str)
		return ((*error = 1));
	return (value * sign);
}
