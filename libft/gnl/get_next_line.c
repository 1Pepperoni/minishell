/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:15:48 by pory              #+#    #+#             */
/*   Updated: 2022/06/14 01:26:56 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	char		*return_value;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	stash = ft_read(fd, stash, buf);
	if (!stash)
		return (NULL);
	return_value = ft_get_line(stash);
	stash = ft_save_the_rest(stash);
	return (return_value);
}

char	*ft_read(int fd, char *stash, char *buf)
{
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (ft_gnl_strchr(stash, '\n') == 1)
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		stash = ft_gnl_strjoin(stash, buf);
	}
	return (stash);
}

/*char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	//printf("stash = %s\n", stash);
	if (ft_strchr(stash, '\n') == 1)
	{
		while (stash[i] != '\n')
			i++;
		line = ft_substr(stash, 0, i + 1);
		//printf("i = %d\n", i);
		//printf("line = %s", line);
	}
	if (stash && ft_strchr(stash, '\n') == 0)
	{
		//printf("hjfkq\n");
		line = ft_substr(stash, 0, ft_strlen(stash));
	}
	return (line);
}*/

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*char	*ft_save_the_rest(char *stash)
{
	int		i;

	i = 0;
	if (ft_strchr(stash, '\n') == 1)
	{
		while (stash[i] != '\n')
			i++;
		stash = ft_substr(stash, i + 1, ft_strlen(stash));
		return (stash);
	}
	return (NULL);
}*/

char	*ft_save_the_rest(char *stash)
{
	char	*storage;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	storage = malloc(sizeof(char) * (ft_gnl_strlen(stash) - i + 1));
	if (!storage)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		storage[j++] = stash[i++];
	storage[j] = '\0';
	free(stash);
	return (storage);
}

/*char	*ft_cut_newline(char *stash)
{
	char	*return_value;
	int		i;
	//char	*tmp;
	
	i = 0;
	if (ft_strchr(stash, '\n') == 1)
	{
		while (stash[i] != '\n')
		{
			i++;
		}
		//printf("25\n");
		//tmp = stash;
		return_value = ft_substr(stash, 0, i);
		//printf("return %s\n", return_value);
		stash = ft_substr(stash, i + 1, ft_strlen(stash));
		//printf("stash %s\n", stash);
		//free (tmp);
		return (return_value);
	}
	if (stash && ft_strchr(stash, '\n') == 0)
	{
		printf("hjfkq\n");
		return_value = ft_substr(stash, 0, ft_strlen(stash));
		//free (stash);
		return (return_value);
	}
	else
		return (NULL);
}*/

/*int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);

	printf("first call\n");
	printf("=> %s", get_next_line(fd));
	printf("\n");
	//free(line);
	printf("second call\n");
	printf("=> %s", get_next_line(fd));
	//free(line);
	printf("\n");
	printf("third call\n");
	printf("=> %s\n", get_next_line(fd));
	//free(line);
	printf("\n");
	printf("4 call\n");
	printf("=> %s\n", get_next_line(fd));
	//free(line);
	printf("\n");
	printf("5 call\n");
	printf("=> %s\n", get_next_line(fd));
	//free(line);
	printf("\n");
	printf("6 call\n");
	printf("=> %s\n", get_next_line(fd));
	//free(line);
	//printf("\n");
	printf("7 call\n");
	printf("=> %s\n", get_next_line(fd));
	//free(line);
	printf("\n");
	//while (1);
}*/

/*int	main(void)
{
	int	fd;
	static char	*stash = NULL;
	char	*buf = NULL;
	//stash = "bonjour\nsalut";
	//char	buf[BUFFER_SIZE + 1];
	
	fd = open("test.txt", O_RDONLY);
	//get_next_line(fd);
	printf("%s\n", ft_read(fd, stash, buf));
	//printf("%s\n", ft_cut_newline(stash));
}*/
