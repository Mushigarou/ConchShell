#include"../inc/built.h"

int	main(int ac, char **av, char **en)
{
	if (ac == 1 && !ft_strncmp((av[0] + 2), "env_f", 6))
	{
		while (*en)
			printf("%s\n", *en++);
	}
}
