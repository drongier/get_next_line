/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:51:16 by drongier          #+#    #+#             */
/*   Updated: 2023/08/08 17:55:02 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src)
	{
		if (src == 0)
			return (ft_strlen(src));
		while ((i + 1) < size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	src_len;

	src_len = ft_strlen(s) + 1;
	dest = (char *) malloc(src_len);
	if (s != NULL && dest != NULL)
		ft_strlcpy(dest, s, src_len);
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destiny;
	size_t	source;
	size_t	result;

	if (((!src || !dst) && !size))
		return (0);
	i = 0;
	result = 0;
	destiny = ft_strlen(dst);
	source = ft_strlen(src);
	if (size > destiny)
		result = source + destiny;
	else
		result = source + size;
	while (size > (destiny + 1) && src[i] != '\0')
	{
		dst[destiny] = src[i];
		destiny++;
		i++;
	}
	dst[destiny] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	free(s1);
	return (new_str);
}
