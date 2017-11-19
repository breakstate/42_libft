/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:53:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/19 15:19:53 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (n *= -1);
	else
		return (n);
}

static char	*ft_count_alloc(int n, int *len)
{
	int		temp_num;
	int		temp_len;
	char	*allocation;

	temp_len = 1;
	if (n < 0)
	{
		temp_len++;
	}
	temp_num = n;
	while (temp_num /= 10)
	{
		temp_len++;
	}
	allocation = ft_memalloc(temp_len + 1);
	if (allocation == NULL)
		return (NULL);
	*len = temp_len;
	return (allocation);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		neg;

	len = 0;
	neg = 0;
	neg += (n < 0) ? 1 : 0;
	str = ft_count_alloc(n, &len);
	while ((len) > 0)
	{
		str[len - 1] = ft_abs(n % 10) + 48;
		n /= 10;
		len--;
	}
	if (neg)
		str[len] = '-';
	return (str);
}

/*
int main(int argc, char **argv)
{
	if (argc)
		printf("yes\n");
	printf("[%s]\n", ft_itoa(atoi(argv[1])));
	return (0);
}
*/
