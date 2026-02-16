/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:10:52 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/11 13:10:54 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

int	ft_checknewline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (i < ft_strlen(s))
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		len;

	len = 0;
	while(s[len] != '\0')
		len++;
	ptr = malloc((len + 1) * sizeof(unsigned char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, s, len + 1);
	return (ptr);
}