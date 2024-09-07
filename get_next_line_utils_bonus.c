/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:05:41 by pirulenc          #+#    #+#             */
/*   Updated: 2023/12/17 10:32:44 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			x;
	unsigned char	*stock;

	x = 0;
	stock = (unsigned char *)s;
	while (x < n)
	{
		stock[x] = 0;
		x++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((long long)nmemb < 0 || (long long)size < 0)
		return (0);
	ptr = malloc(nmemb * size);
	if (!(ptr))
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*dest;
	size_t	len_m;
	size_t	y;

	if (!(s))
		return (0);
	y = 0;
	len_m = ft_strlen(s) - start;
	if (len_m >= len)
		len_m = len;
	if (start > ft_strlen(s))
		len_m = 0;
	dest = malloc((len_m + 1) * sizeof(char));
	if (!(dest))
		return (0);
	ft_bzero(dest, len_m + 1);
	while (y < len_m)
		dest[y++] = s[start++];
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	x;
	size_t	y;

	if (s1)
		x = (ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		x = ft_strlen(s2) + 1;
	dest = ft_calloc(sizeof(char), x);
	if (!(dest))
		return (0);
	y = 0;
	x = 0;
	if (s1)
	{
		while (s1[y] != '\0' && s1)
			dest[x++] = s1[y++];
	}
	y = 0;
	while (s2[y] != '\0')
		dest[x++] = s2[y++];
	if (s1)
		free(s1);
	return (dest);
}
