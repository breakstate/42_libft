#include "includes/libft.h"
#include <stdio.h>

static char		*ft_get_words(char *str, char c, int index)
{
	int		i;
	int		count;
	int		delim_flag;
	int		pos;

	i = 0;
	delim_flag = 0;
	count = 0;
	pos = 0;
	while (str[i])
	{
		if (str[i] == c)
			delim_flag = 0;
		if (str[i] != c)
		{
			delim_flag = 1;
			pos = i;
		}
		if (delim_flag == 1)
			count++;
		while (str[i] != c)
			i++;
		if (index == (count))
			return (ft_strsub(str, pos, i - pos));
		i++;
	}
	return (NULL);//?
/*
	while (str[i])
	{
		if (str[i] != c)
		{
			delim_flag = 1;
			pos = 
		}
	}
	*/
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
static int		_count_words(char *str, char c)
{
	int		i;
	int		count;
	int		delim_flag;

	i = 0;
	delim_flag = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			delim_flag = 0;
		if (str[i] != c && delim_flag == 0)
		{
			delim_flag = 1;
			count++;
		}
		while (str[i] != c)
			i++;
		i++;
	}
	return (count);
}

static int		ft_count_words(char *str, char c)
{
	int		i;
	int		count;
	int		delim_flag;

	i = 0;
	delim_flag = 0;
	count = 0;
	while (str[i])
	{
		printf("i = [%c]\n", str[i]);
		if (str[i] == c)
			delim_flag = 0;
		if (str[i] != c)
			delim_flag = 1;
		if (delim_flag == 1)
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (!str[i])
			return (count);
		i++;
	}
	return (count);
}

/*
char	**strsplit(char *str, char c)
{
	int		word_count;
	char	**word_array;

	word_count = ft_count_words(str, c);

	//word_array = ft_populate(str, word_count, c);
}
*/
int		main()
{
	int i = 4;
	printf("[%d]\n", ft_count_words("hello", ' '));
	printf("word %d = [%s]\n", i, ft_get_words("hello", ' ', i));

	return (0);
}