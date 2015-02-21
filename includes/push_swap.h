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
# define HELP 0b00000001
# define ISHELP(x) (x & HELP ? 1 : 0)
# define VISUAL 0b00000010
# define ISVISUAL(x) (x & VISUAL ? 1 : 0)
# define COLOR 0b00000100
# define ISCOLOR(x) (x & COLOR ? 1 : 0)
# define OVERFLOW 0b00001000
# define ISOVERFLOW(x) (x & OVERFLOW ? 1 : 0)
# define DOUBLES 0b00010000
# define ISDOUBLES(x) (x & DOUBLES ? 1 : 0)

typedef struct		s_lst
{
	int				value;
	struct s_lst	*next;
}					t_lst;

int					ft_put_return(char *str, int val);
int					ft_lowest(t_lst **l, int here);
int					ft_atoi(const char *str, char *error, int flags);
int					ft_order(int a, int b, int c);
int					ft_ordered(t_lst *head);
int					ft_doubles(t_lst **la);


int					ft_strncmp(char *a, char *b);
int					ft_getflags(int *ac, char ***av);

void				ft_testav(int ac, char **av);
void				ft_testflags(int flags);
#endif
