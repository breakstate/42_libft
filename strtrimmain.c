#include <stdio.h>
#include "includes/libft.h"

int main()
{
	char *str;
	char *trimmed;

	str = " d d";
	trimmed = ft_strtrim(str);
	printf("[%s]\n", trimmed);
	return (0);
}

