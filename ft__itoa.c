/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:53:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/09 15:49:21 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

int ft_abs(int	n)
{
	return (n *= -1);
}

char	*count_digits(int	num, int *len)
{
	int 	count;
	long	lnum;
	char	*str;
	int		sign;

	lnum = num;
	count = 2;
	if (lnum < 0)
	{
		sign = -1;
		count++;
		lnum = -lnum;
	}
	while ((lnum / 10) > 0)
	{
		lnum = lnum/10;
		count++;
	}
	str = ft_memalloc(count);
	*len = count - 1;
	printf("count = %d\n", count);
	return (str);
}

char *itoa(int n)
{
	long	div;
	int		mod;
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = count_digits(n, &len);
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	while (n != 0)
	{
		str[len] = (ft_abs(n % 10) + 48);
		printf("str[%d] = %c\n", len, str[len]);
		n = n / 10;
		len--;
	}
	printf("[%s]\n", str);
	return (NULL);
}

int main(int argc, char **argv)
{
	itoa(atoi(argv[1]));
	return (0);
}

//count digits and malloco string
//mod and divide to pupulate string
//bells and whistles - \0
//resturn