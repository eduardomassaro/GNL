/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epagne-m <epagne-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:29:27 by epagne-m          #+#    #+#             */
/*   Updated: 2020/05/31 22:55:38 by epagne-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*s_line;
	char			*l_buffer;
	register int	result;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	result = 1;
	*line = NULL;
	l_buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!s_line)
		s_line = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (newline(s_line) == -1 && result >= 1 && result <= BUFFER_SIZE)
	{
		result = read(fd, l_buffer, BUFFER_SIZE);
		if (result >= 1 && result <= BUFFER_SIZE && s_line)
			s_line = ft_strjoin(s_line, l_buffer);
		ft_bzero(l_buffer);
	}
	if (result >= 0 && result <= BUFFER_SIZE)
		s_line = cleanline(line, s_line, newline(s_line));
	free(l_buffer);
	if (result >= 1 && result <= BUFFER_SIZE)
		return (1);
	return (result == 0 ? 0 : -1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	register int	i;
	register int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)ft_calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

char	*cleanline(char **line, char *s_line, int j)
{
	char	*l_temp;

	if (j >= 0)
	{
		s_line[j] = '\0';
		*line = (char*)ft_calloc(ft_strlen(s_line) + 1, sizeof(char));
		l_temp = (char*)ft_calloc(ft_strlen(&s_line[j + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
		ft_strlcpy(l_temp, &s_line[j + 1], ft_strlen(&s_line[j + 1]) + 1);
		free(s_line);
		s_line = NULL;
		return (l_temp);
	}
	*line = (char*)ft_calloc(ft_strlen(s_line) + 1, sizeof(char));
	ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
	free(s_line);
	s_line = NULL;
	return (s_line);
}

int		newline(char *s_line)
{
	int	i;

	i = 0;
	if (!s_line)
		return (-1);
	while (s_line[i])
	{
		if (s_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
