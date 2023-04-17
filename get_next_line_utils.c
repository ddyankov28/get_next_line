/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:52:13 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/17 23:07:23 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*news;
	int		i;

	i = 0;
	news = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!news)
		return (NULL);
	while (s[i])
	{
		news[i] = s[i];
		i++;
	}
	news[i] = '\0';
	return (news);
}

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	while (*a != '\0' && *a != (unsigned char)c)
		a++;
	if (*a == (unsigned char)c)
		return ((char *)a);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	news = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!news)
		return (NULL);
	while (s1[a])
		news[b++] = s1[a++];
	a = 0;
	while (s2[a])
		news[b++] = s2[a++];
	news[b] = '\0';
	return (news);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (s)
	{
		if (start >= ft_strlen(s))
			return (ft_strdup(""));
		if (ft_strlen(s) > len)
			subs = (char *)malloc(sizeof(char) * (len + 1));
		if (ft_strlen(s) <= len)
			subs = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (!subs)
			return (NULL);
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			subs[i] = s[start + i];
			i++;
		}
		subs[i] = '\0';
		return (subs);
	}
	return (0);
}
