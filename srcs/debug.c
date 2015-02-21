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