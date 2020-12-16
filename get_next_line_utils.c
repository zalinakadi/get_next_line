/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 21:04:27 by eproveme          #+#    #+#             */
/*   Updated: 2020/12/16 16:14:46 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			i++;
		}
		return (i);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	if (s1)
	{
		i = 0;
		len = ft_strlen(s1);
		if (!(s2 = ((char *)malloc(sizeof(char) * (len + 1)))))
			return (0);
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (str + i);
			i++;
		}
		if (s[i] == '\0' && c == '\0')
			return (str + i);
	}
	return (0);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	n;

	n = 0;
	while (src[n] != '\0')
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 || s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		str = NULL;
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s1 && s1[j])
			str[i++] = s1[j++];
		j = 0;
		while (s2 && s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}
