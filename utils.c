#include "push_swap.h"
#include "libft/libft.h"

int				ft_isnum(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int				ft_put_return(char *str, int val)
{
	ft_putstr(str);
	return (val);
}

void			ft_putstrloop(char *str, size_t times)
{
	while (times--)
		ft_putstr(str);
}
