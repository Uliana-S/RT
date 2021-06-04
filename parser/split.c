#include "main_header.h"

int	count_words(char *str, char sep)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			while (str[i] != sep && str[i] != '\0')
				i++;
			res++;
		}
		else
			i++;
	}
	return (res);
}

char	*create_word(char *str, int start, int finish)
{
	char	*res;
	int		i;

	res = ft_calloc((finish - start + 2), sizeof(char));
	if (res)
	{
		i = 0;
		while (start + i <= finish)
		{
			res[i] = str[start + i];
			i++;
		}
	}
	return (res);
}

char	**free_str(char **res_str, int j)
{
	while (j > 0)
	{
		free(res_str[j - 1]);
		j--;
	}
	free(res_str);
	error_processing1(3);
	return (NULL);
}

char	**search_words(char **res_str, char *str, char sep)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			start = i;
			while (str[i] != sep && str[i] != '\0')
				i++;
			res_str[j] = create_word(str, start, i - 1);
			if (!res_str[j])
				return (free_str(res_str, j));
			j++;
		}
		else
			i++;
	}
	return (res_str);
}

char	**ft_split(char *str, char sep)
{
	int		count;
	char	**res_str;

	res_str = NULL;
	if (!str)
		return (NULL);
	count = count_words(str, sep);
	res_str = ft_calloc((count + 1), sizeof(char *));
	if (res_str)
	{
		res_str = search_words(res_str, str, sep);
		res_str[count] = 0;
	}
	return (res_str);
}
