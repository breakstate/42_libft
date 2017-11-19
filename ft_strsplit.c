/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:50:35 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/18 12:50:40 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static void		ft_gw_helper(int *count, int *flag, int *pos, int i)
{
	(*count)++;
	*flag = 1;
	*pos = i;
}

static char		*ft_get_words(const char *str, char c, int index)
{
	int		i;
	int		count;
	int		flag;
	int		pos;

	i = -1;
	flag = 0;
	count = 0;
	pos = 0;
	while (str[i++])
	{
		if (str[i] == c)
			flag = 0;
		else if (str[i] != c && flag == 0)
			ft_gw_helper(&count, &flag, &pos, i);
		if (index == (count))
		{
			while (str[i] != c)
				i++;
			return (ft_strsub(str, pos, i - pos));
		}
	}
	return (0);
}
/*
static char		**ft_populate(char *str, int count, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		split[i] = (ft_get_words(str, c, i + 1));
	}
}
*/

static int		ft_count_words(const char *str, char c)
{
	int		i;
	int		count;
	int		flag;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

char	**ft_strsplit(const char *str, char c)
{
	int		i;
	int		count_words;
	char	**word_array;

	i = 0;
	count_words = ft_count_words(str, c);
	word_array = (char **)ft_memalloc(sizeof(char *) * (count_words + 1));
	if (word_array == NULL)
		return (NULL);
	while (i < count_words)
	{
		word_array[i] = ft_get_words(str, c, i + 1);
		i++;
	}
	word_array[i] = 0;
	return (word_array);
}
/*
int		main()
{
	char **split;
	int i = 4;
	int j = 0;
	//printf("[%d]\n", ft_count_words("hello my name is", ' '));
	//printf("word %d = [%s]\n", i, ft_get_words("hello my name is", ' ', i));

	split = ft_strsplit("***salut****!**", '*');
	while (split[j])
	{
		printf("split[%d] = [%s]\n", j, split[0]);
		j++;
	}
	return (0);
}
*/
