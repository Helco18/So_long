/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:40:08 by gcannaud          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:28 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd)
{
	int		size;
	char	*save;
	char	*buf;

	size = 1;
	save = NULL;
	while (size > 0)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf)
			size = read(fd, buf, BUFFER_SIZE);
		if (!buf || size < 0)
		{
			if (buf)
				free(buf);
			if (save)
				free(save);
			return (NULL);
		}
		buf[size] = 0;
		save = ft_strdeljoin(save, buf);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*str2;
	static char	*str3[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	str2 = ft_set_str2(fd, str3[fd]);
	if (!str2 || str2[0] == 0)
	{
		if (str2 && str2[0] == 0)
			free(str2);
		str3[fd] = NULL;
		return (NULL);
	}
	str = ft_set_str(str2);
	if (!str)
		return (NULL);
	str3[fd] = ft_set_str3(str2, str);
	if (!str3[fd])
		return (NULL);
	free(str2);
	return (str);
}

char	*ft_set_str2(int fd, char *str3)
{
	char	*str2;

	str2 = ft_read(fd);
	str2 = (ft_strdeljoin(str3, str2));
	return (str2);
}

char	*ft_set_str(char *str2)
{
	char	*str;
	int		i;

	i = 1;
	while (str2[i] != 0 && str2[i - 1] != '\n')
		i++;
	str = ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (str2[i] != '\0' && str2[i] != '\n')
	{
		str[i] = str2[i];
		i++;
	}
	if (str2[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*ft_set_str3(char *str2, char *str)
{
	char	*str3;
	int		i;
	int		c;

	c = 0;
	i = ft_strlen(str);
	str3 = ft_calloc((ft_strlen(str2) - i + 1), sizeof(char));
	if (!str3)
		return (NULL);
	while (str2[i] != 0)
		str3[c++] = str2[i++];
	str3[c] = '\0';
	return (str3);
}
