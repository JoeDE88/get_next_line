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
	static char	*stash;
	char		*buf;

	if (stash == NULL)
		stash = ft_strdup("", 1);
	buf = read_buf(&stash, fd);
	return (buf);
}

char	*ft_truncate(char *stash, char **aux, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (stash[i] != c)
		i++;
	ptr = (ft_strchr(stash, '\n') + 1);
	*aux = ft_strdup(stash, i - 1);
	stash = ptr;
	return (stash);
}

char	*read_buf(char **stash, int fd)
{
	int		bytes_read;
	char	*buf;
	char	*aux;

	bytes_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	while (ft_strchr(*stash, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read > 0)
			ft_copyline(stash, buf, aux, bytes_read);
		if (bytes_read == 0)
		{
			return (*stash);
		}
	}
	*stash = ft_truncate(*stash, &aux, '\n');
	return (aux);
}

void	ft_copyline(char **stash, char *buf, char *aux, int bytes)
{
	int	len;

	if (bytes == BUFFER_SIZE)
	{
		len = BUFFER_SIZE + ft_strlen(*stash);
		aux = malloc((len + 1) * sizeof(char));
		if (aux == NULL)
			return ;
		ft_strcpy(aux, *stash, ft_strlen(*stash));
		ft_strcpy(aux + ft_strlen(*stash), buf, ft_strlen(buf));
		aux[len] = '\0';
		*stash = aux;
	}
	if (bytes < BUFFER_SIZE)
	{
		len = bytes + (int)ft_strlen(*stash);
		aux = malloc((len + 1) * sizeof(char));
		if (aux == NULL)
			return ;
		ft_strcpy(aux, *stash, ft_strlen(*stash));
		ft_strcpy(aux + ft_strlen(*stash), buf, ft_strlen(buf));
		aux[len] = '\0';
		*stash = aux;
	}
}
