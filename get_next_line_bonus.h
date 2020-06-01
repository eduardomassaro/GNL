/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epagne-m </var/mail/epagne-m>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:40:26 by epagne-m          #+#    #+#             */
/*   Updated: 2020/05/31 21:41:00 by epagne-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		newline(char *s_line);
char	*ft_strjoin(char *s1, char *s2);
char	*cleanline(char **line, char *s_line, int index_newline);
size_t	ft_strlen(char *str);
void	ft_bzero(char *str);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
