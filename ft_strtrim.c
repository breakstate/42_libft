/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:57:04 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/16 11:51:24 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	
	i = 0;
	end = 0;
	start = 0;
	if (s)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s)
			i++;
		start = i;
		i = ft_strlen(s) - 1;
		while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s)
		{
			i--;
		//	printf("len = [%d]\n", i);//debug
		}
		end = i + 1;
		//printf("start = [%d], end = [%d], end - start = [%d]\n", start, end, end - start);//debug
		if ((end - start) > 0)
		{
			return (ft_strsub(s, start, end - start));
		}
		else 
			return (""); 
	}
	return (NULL);
}
/*
char	*ft_strtrim(char const *s)
{
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	len = ft_strlen(s);
	if (s != NULL)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			if (i == (len - 1))
				return ("");
			i++;
		}
		j = (len - 1);
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		j = j - i + 1;
		return (ft_strsub(s, i, j));
	}
	return (NULL);
}
*/
/*
int main()
{
	char *str = "";
	printf("[%s]\n", ft_strtrim(str));
	return (0);
}
*/

