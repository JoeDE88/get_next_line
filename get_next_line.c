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

	aux = NULL;
	if (stash == NULL)
	{
		stash = malloc(BUFFER_SIZE);
		read(fd, stash, BUFFER_SIZE);
	}
	while (stash != NULL)
	{
		stash = read_buf(stash, fd);
		if (ft_checknewline(stash))
		{
			ft_truncate(stash, aux, '\n');
			break;
		}
	}
	return (stash);
}

void    ft_truncate(char *stash, char *aux, char c)
{
	int	i = 0;
	char *ptr;

	while (stash[i] != c)
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return ;
	ptr[i] = '\0';
	while (i >= 0)
	{
		ptr[i] = stash[i];
		i--;
	}
	aux = ptr;
	printf("aux inside truncate: %s\n", aux);
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