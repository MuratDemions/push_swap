#include "push_swap.h"

int	*parse_args(int argc, char **argv, int check_buf)
{
	int	*arr;
	int	i;
	int	j;

	arr = malloc(sizeof(int) * (argc - 1 - check_buf));
	if (!arr)
		return (NULL);
	i = 1 + check_buf;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| (argv[i][j] == '-' || argv[i][j] == '+')))
			{
				write(1, "Error", 6);
				return (NULL);
			}
			j++;
		}
		arr[i - 1 - check_buf] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}
