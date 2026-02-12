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
	int	i;

	i = 0;
	if (stash == NULL)
	{
		stash = malloc(BUFFER_SIZE);
		read(fd, stash, BUFFER_SIZE);
	}
	while (!ft_checknewline(stash))
	{
		if (!ft_checknewline(stash))
		{
			stash = read_buf(stash, fd);
			printf("stash: %s\n", stash);
		}
		else
		{
			int i = read(fd, aux, BUFFER_SIZE);
			aux = malloc(i + 1);
			printf("aux: %s\n", aux);
		}
	}
	printf("stash: %s\n", stash);
	return (stash);
}

char	*read_buf(char *stash, int fd)
{
	int		bytes_read;
	char	buf[BUFFER_SIZE + 1];
	char	*aux = NULL;
	char	*tmp;
	size_t	len;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		tmp = buf;
		len = BUFFER_SIZE + ft_strlen(stash);
		aux = malloc((len + 1) * sizeof(char));
		ft_strcpy(aux, stash, ft_strlen(stash));
		ft_strcpy(aux + ft_strlen(stash), tmp, ft_strlen(tmp));
	}
	stash = aux;
	return (stash);
}