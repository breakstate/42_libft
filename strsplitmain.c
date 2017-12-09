#include <stdio.h>
#include "includes/libft.h"

int main()
{
	//char	*str;
	char	**split;
	int		i = 0;

	split = ft_strsplit("***salut****!**", '*');

	printf("first = [%s]\n\n", split[i]);
	while (split && split[i])
	{
		printf("[%s]\n", split[i]);
		i++;
	}
	return (0);
}
