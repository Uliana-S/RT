#include "main_header.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;

	res = (char *)malloc(size * nmemb);
	if (res)
	{
		ft_bzero(res, size * nmemb);
		return (res);
	}
	error_processing1(3);
	return (NULL);
}
