/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:20:03 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/10 17:20:39 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char	*aux;
	int	i = 0;

	aux = NULL;
	if (stash == NULL)
	{
		stash = malloc(BUFFER_SIZE);
		read(fd, stash, BUFFER_SIZE);
	}
	while (stash != NULL)
	{
		++i;
		stash = read_buf(stash, fd);
		if (ft_checknewline(stash))
		{
			stash = ft_truncate(stash, &aux, '\n');
			break;
		}
	}
	return (aux);
}

char    *ft_truncate(char *stash, char **aux, char c)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char 	*ptr;
	char	*rem;

	while (stash[i] != c)
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	while (j < i)
	{
		ptr[j] = stash[j];
		j++;
	}
	*aux = ptr;
	k = 1;
	while (stash[i+k] != '\0')
	k++;
	rem = malloc((k + 1) * sizeof(char));
	if (rem == NULL)
		return (NULL);
	rem[k] = '\0';
	ft_strcpy(rem, stash+i+1, k);
	return (rem);
}

char	*read_buf(char *stash, int fd)
{
	int		bytes_read;
	char	buf[BUFFER_SIZE];
	char	*aux;
	int		len;

	aux = NULL;
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		len = BUFFER_SIZE + (int)ft_strlen(stash);
		aux = malloc((len + 1) * sizeof(char));
		if (aux == NULL)
			return (NULL);
		ft_strcpy(aux, stash, ft_strlen(stash));
		ft_strcpy(aux + ft_strlen(stash), buf, ft_strlen(buf));
		aux[len] = '\0';
	}
	else
	{
		int i = 0;
		while (buf[i] != '\0')
			i++;
		printf("i: %d ---- buf: %p ---- stash: '%s'\n", i, buf, stash);
	}
	stash = aux;
	return (stash);
}