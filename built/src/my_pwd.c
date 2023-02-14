#include"../inc/built.h"

int	main(void)
{
	char	cd[PATH_MAX];

	if (getcwd(cd, sizeof(cd)))
		printf("%s\n", cd);
	else
		return (ft_printf("PWD: %s\n", 2, strerror(errno)), errno);
}
