#include"../inc/execution.h"

int	main()
{
	char	cd[PATH_MAX];

	if (getcwd(cd, sizeof(cd)))
		printf("%s\n", cd);
	else
		perror("MINI_SHELL:");
}
