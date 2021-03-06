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

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define REV_RU 1

typedef struct		s_lst
{
	int				value;
	struct s_lst	*ne;
}					t_lst;

int					ft_isnum(char *str);
int					ft_put_return(char *str, int val);
void				ft_putstrloop(char *str, int times, int len);
int					ft_lowest(t_lst **l, int here);
int					ft_atoi(const char *str, char *error);
int					ft_order(int a, int b, int c);
int					ft_ordered(t_lst *head, int len);
int					ft_doubles(t_lst **la);

#endif
