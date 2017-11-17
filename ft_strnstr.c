/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:25:53 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/16 11:10:26 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(little) < 1)
		return ((char *)big);
	while (big[i] && i < (int)len)
	{
		while (big[i + j] == little[j] && i + j < (int)len)
		{
			j++;
			if (little[j] == '\0' && (i + j) <= (int)len)
				return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	//if little is empty, return big
	//search big for first character of little
	//when found, step through both to see if whole of little is present
	//if end of big is reached before we find an instance of little, return NULL.
	//if little is present return pointer to first char of little within big
	
	int		i;
	int		j;
	int	ilen = (int)len;

	i = 0;
	j = 0;
	if (little[0] != '\0')
	{
		while (big[i] && i < ilen)
		{
			if (big[i] == little[j])
			{
				while (big[i + j] == little[j] && big[i + j] && (i + j) < ilen)
				{
					j++;
					if (little[j] == '\0')
						return ((char *)&big[i]);
				}
				j = 0;
			}
			i++;
		}
	}
	else
		return ((char *)big);
	return (NULL);
}
/*
int		main()
{
	char *big = "The quick brown fox jumps over the lazy dog.";
	char *little = "g.asd";

	printf("my result = %s.\n", ft_strstr(big, little));
	printf("system result = %s.\n", strstr(big, little));
	return (0);
}
*/