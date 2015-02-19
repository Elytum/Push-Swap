/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 03:39:44 by achazal           #+#    #+#             */
/*   Updated: 2014/11/10 18:54:06 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_lst
{
	int				value;
	struct s_lst	*next;
}					t_lst;

int				ft_isnum(char *str);
int				ft_put_return(char *str, int val);
void			ft_putstrloop(char *str, int times);
int				ft_lowest(t_lst **l);
void			ft_pushback(t_lst **head, int v);
int				ft_atoi(const char *str);
#endif
