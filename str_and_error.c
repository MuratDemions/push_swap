#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	spt_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
