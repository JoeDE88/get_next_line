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
	static char	str[BUFFER_SIZE];
	char	*tmp;
	int	bytes;

	tmp = NULL;
	bytes = read(fd, str, BUFFER_SIZE);
	if (!ft_checknewline(str))
	{
		tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (tmp == NULL)
		{
			printf("no space left");
			return (NULL);
		}
		ft_strcpy(tmp, str, BUFFER_SIZE);
	}

	return (str);
}
