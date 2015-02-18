/*int				ft_highest(t_lst **l)
{
	t_lst		*ptr;
	t_lst		*before_highest;
	int			value;
	int			i;
	int			pos;

	ptr = *l;
	value = ptr->value;
	before_highest = NULL;
	i = 0;
	pos = i;
	while (ptr->next)
	{
		if (ptr->next->value > value)
		{
			value = ptr->next->value;
			before_highest = ptr;
			pos = i + 1;
		}
		ptr = ptr->next;
		i++;
	}
	if (before_highest)
	{
		ptr = before_highest->next;
		before_highest->next = ptr->next;
	}
	else
	{
		ptr = *l;
		*l = ptr->next;
	}
	free(ptr);
	return (pos);
}*/


/*void			ft_disorder(int a, int b, int c)
{
	if (a >= b && b >= c && a >= c) // 3 2 1
		return ;
	else if (a <= b && b <= c) // 1 2 3
		ft_putstr("sa rra ");
	else if (a <= b && b >= c && a <= c) // 1 3 2
		ft_putstr("ra ");
	else if (a >= b && b <= c && a <= c) // 2 1 3
		ft_putstr("rra ");
	else if (a <= b && b >= c && a >= c) // 2 3 1
		ft_putstr("sa ");
	else if (a >= b && b <= c && a >= c) // 3 1 2
		ft_putstr("rra sa ");
	else
		ft_putstr("ERROR\n");
}*/

/*void			ft_putlst(t_lst *head)
{
	t_lst		*ptr;

	ptr = head;
	while (ptr)
	{
		ft_putnbr(ptr->value);
		ft_putchar(' ');
		ptr = ptr->next;
	}
	ft_putchar('\n');
}*/

/*void			ft_putlstrev(t_lst *head)
{
	t_lst		*ptr;

	ptr = head;
	while (ptr->next)
		ptr = ptr->next;
	while (ptr)
	{
		ft_putnbr(ptr->value);
		ft_putchar(' ');
		ptr = ptr->past;
	}
	ft_putchar('\n');
}*/

/*void			ft_putrot(t_lst *head, int pos)
{
	t_lst		*ptr;
	int			c;

	ft_putstr("\tRotated (pos = ");
	ft_putnbr(pos);
	ft_putstr(") : ");
	ptr = head;
	c = pos;
	while (ptr && c-- > 0)
		ptr = ptr->next;
	while (ptr)
	{
		ft_putnbr(ptr->value);
		ft_putchar(' ');
		ptr = ptr->next;
	}
	ptr = head;
	c = pos;
	while (ptr && c-- > 0)
	{
		ft_putnbr(ptr->value);
	ft_putchar(' ');
		ptr = ptr->next;
	}
	ft_putchar('\n');
}*/
