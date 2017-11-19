/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:25:53 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/19 15:28:09 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
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
