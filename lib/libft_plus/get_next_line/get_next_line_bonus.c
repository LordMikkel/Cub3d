/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:11:10 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 19:57:32 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static void	cleanup_all_stash(char **stash)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (stash[i])
			ft_free((void **)&stash[i]);
		i++;
	}
}

static char	*read_into_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	buffer = ft_alloc(1, BUFFER_SIZE + 1);
	if (stash == NULL)
		stash = ft_strdup("");
	if (!buffer || !stash)
		return (ft_free((void **)&buffer), ft_free((void **)&stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free((void **)&buffer), ft_free((void **)&stash), NULL);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		ft_free((void **)&stash);
		stash = tmp;
		if (!stash || !tmp)
			return (ft_free((void **)&buffer), NULL);
	}
	if (bytes_read == 0 && *stash == '\0')
		return (ft_free((void **)&buffer), ft_free((void **)&stash), NULL);
	return (ft_free((void **)&buffer), stash);
}

static char	*extract_line(char *stash)
{
	size_t		len;
	char		*newline_ptr;
	char		*line;

	if (!stash || *stash == '\0')
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (newline_ptr)
		len = newline_ptr - stash + 1;
	else
		len = ft_strlen(stash);
	line = ft_substr(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*remain_stash(char *stash)
{
	char	*newline_ptr;
	char	*remaining;

	if (!stash)
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (!newline_ptr)
	{
		ft_free((void **)&stash);
		return (NULL);
	}
	remaining = ft_strdup(newline_ptr + 1);
	ft_free((void **)&stash);
	if (!remaining)
		return (NULL);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd == RESET)
	{
		cleanup_all_stash(stash);
		return (NULL);
	}
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_into_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
	{
		ft_free((void **)&stash[fd]);
		return (NULL);
	}
	stash[fd] = remain_stash(stash[fd]);
	return (line);
}
