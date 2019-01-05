/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:25:45 by rsathiad          #+#    #+#             */
/*   Updated: 2018/08/11 18:54:40 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_findnewline(char **fdlist, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while ((fdlist[fd][len] != '\n' && fdlist[fd][len] != '\0'))
		len++;
	if (fdlist[fd][len] == '\n')
	{
		*line = ft_strsub(fdlist[fd], 0, len);
		tmp = ft_strdup(fdlist[fd] + (len + 1));
		free(fdlist[fd]);
		fdlist[fd] = tmp;
		if (fdlist[fd][0] == '\0')
			ft_strdel(&fdlist[fd]);
	}
	else if (fdlist[fd][len] == '\0')
	{
		*line = ft_strdup(fdlist[fd]);
		ft_strdel(&fdlist[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*fdlist[4864];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(fdlist[fd]))
			fdlist[fd] = ft_strnew(0);
		tmp = ft_strjoin(fdlist[fd], buf);
		free(fdlist[fd]);
		fdlist[fd] = tmp;
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && fdlist[fd] == NULL)
		return (0);
	else
		return (ft_findnewline(fdlist, line, fd));
}
