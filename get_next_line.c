/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:15:18 by pirulenc          #+#    #+#             */
/*   Updated: 2023/12/17 10:30:53 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_n(char *stock)
{
	int	x;
	int	len_total;

	x = 0;
	len_total = ft_strlen(stock);
	while (stock[x] != '\n' && x < len_total)
		x++;
	if (x == len_total)
		return (-1);
	else
		return (x);
}

char	*ft_read_n(int fd, char *stock)
{
	char	*tempo;
	int		check;

	check = BUFFER_SIZE;
	tempo = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (check == BUFFER_SIZE)
	{
		check = read(fd, tempo, BUFFER_SIZE);
		if (check == -1)
		{
			free(stock);
			stock = NULL;
			free(tempo);
			return (stock);
		}
		tempo[check] = '\0';
		stock = ft_strjoin(stock, tempo);
		if (ft_check_n(stock) != -1)
			break ;
	}
	free(tempo);
	return (stock);
}

char	*ft_split_n(char **stock)
{
	int		x;
	char	*dest;
	char	*tempo;

	if (!*stock)
	{
		free(*stock);
		return (NULL);
	}
	dest = NULL;
	tempo = NULL;
	x = ft_check_n(*stock);
	if (x == -1)
	{
		dest = ft_strjoin(dest, *stock);
		free(*stock);
		*stock = NULL;
		return (dest);
	}
	dest = ft_substr(*stock, 0, (x + 1));
	tempo = ft_substr(*stock, (x + 1), (ft_strlen(*stock) - x));
	free(*stock);
	*stock = ft_substr(tempo, 0, ft_strlen(tempo));
	free(tempo);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*dest;

	dest = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock)
	{
		stock = ft_calloc(sizeof(char), 1);
	}
	stock = ft_read_n(fd, stock);
	dest = ft_split_n(&stock);
	if (!stock || !stock[0])
	{
		free(stock);
		stock = NULL;
	}
	if (!dest || !dest[0])
	{
		free(dest);
		return (NULL);
	}
	else
		return (dest);
}
