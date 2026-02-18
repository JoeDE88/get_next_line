/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:20:03 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/18 18:01:58 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buf(char *stash, int fd);
static char	*extract_line(char *stash);
static char	*get_next_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (stash == NULL)
		stash = ft_strdup("");
	stash = read_buf(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	if (line == NULL)
		return (NULL);
	stash = get_next_stash(stash);
	return (line);
}

static char	*read_buf(char *stash, int fd)
{
	int			bytes_read;
	static int	last;
	char		*buf;
	char		*aux;

	if (last == 1)
		return (NULL);
	bytes_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(stash, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			aux = ft_copyline(stash, buf, bytes_read);
		}
		if (aux == NULL)
			return (NULL);
		free(stash);
		stash = aux;
	}
	free(buf);
	return (stash);
}

char	*ft_copyline(char *stash, char *buf, int bytes)
{
	char	*aux;
	int		len;

	len = 0;
	if (ft_strlen(stash) == 0)
		len = bytes;
	else
		len = bytes + ft_strlen(stash);
	aux = ft_strjoin(stash, buf);
	stash = aux;
	return (aux);
}

static char	*extract_line(char *stash)
{
	char	*line;
	char	*position;
	size_t	len;

	if (stash == NULL)
		return (NULL);
	position = ft_strchr(stash, '\n');
	if (position == NULL)
		len = ft_strlen(stash);
	else
		len = (position - stash) + 1;
	line = ft_substr(stash, 0, len);
	return (line);
}

static char	*get_next_stash(char *stash)
{
	char	*new_stash;
	char	*line_pos;
	size_t	len;
	
	line_pos = ft_strchr(stash, '\n');
	if (line_pos == NULL)
		return (NULL);
	len = ft_strlen(line_pos + 1);
	if (len == 0)
		return (NULL);
	new_stash = ft_substr(line_pos + 1, 0, len);
	free(stash);
	return (new_stash);
}