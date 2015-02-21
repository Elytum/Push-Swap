#include "push_swap.h"

int				ft_doubles(t_lst **la)
{
	t_lst		*head;
	t_lst		*ptr;

	if (!la || !*la)
		return (0);
	head = *la;
	while (head)
	{
		ptr = head->next;
		while (ptr)
		{
			if (head->value == ptr->value)
				return (1);
			ptr = ptr->next;
		}
		head = head->next;
	}
	return (0);
}