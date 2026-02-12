/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:14:30 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/10 17:14:32 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_checknewline(char *s);
void	ft_strcpy(char *dst, char *src, int n);
size_t	ft_strlen(const char *s);
char	*read_buf(char *stash, int fd);
void    ft_truncate(char *stash, char *aux, char c);
#endif
