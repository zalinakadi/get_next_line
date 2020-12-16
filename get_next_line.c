/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:33:44 by eproveme          #+#    #+#             */
/*   Updated: 2020/12/16 16:47:30 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_free(char *buff, int i)
{
	free(buff);
	buff = NULL;
	return (i);
}

int				ft_rmd(char *rmd, char **line)
{
	char	*ind;

	ind = NULL;
	if (rmd)
	{
		if ((ind = ft_strchr(rmd, '\n')))
		{
			*ind = '\0';
			if (!(*line = ft_strdup(rmd)))
				return (-1);
			ind++;
			ft_strcpy(rmd, ind);
			return (1);
		}
	}
	return (0);
}

int				ft_line(char *ind, char **line, char **rmd, char *buff)
{
	*ind = '\0';
	ind++;
	if (!(*line = ft_strjoin(*rmd, buff)))
		return (ft_free(buff, -1));
	free(*rmd);
	*rmd = NULL;
	if (!(*rmd = ft_strjoin(*rmd, ind)))
		return (ft_free(buff, -1));
	return (ft_free(buff, 1));
}

int				ft_read(int fd, char **line, char *buff)
{
	static char	*rmd;
	char		*ind;
	char		*tmp;
	int			rd;

	if ((rd = ft_rmd(rmd, line)))
		return (ft_free(buff, rd));
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if ((ind = ft_strchr(buff, '\n')))
			return (ft_line(ind, line, &rmd, buff));
		tmp = rmd;
		if (!(rmd = ft_strjoin(rmd, buff)))
			return (ft_free(buff, -1));
		ft_free(tmp, 0);
	}
	ft_free(buff, 0);
	if (!(buff = ft_strdup("")))
		return (ft_free(buff, -1));
	if (!(*line = ft_strjoin(rmd, buff)))
		return (ft_free(buff, -1));
	free(rmd);
	rmd = NULL;
	return (ft_free(buff, 0));
}

int				get_next_line(int fd, char **line)
{
	char		*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (ft_free(buff, -1));
	*line = NULL;
	return (ft_read(fd, line, buff));
}
