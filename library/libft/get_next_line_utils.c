/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:18:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/05/02 20:02:35 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&(s[i]));
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&(s[i]));
	return (NULL);
}

unsigned int	gnl_strlen(char *str)
{
	unsigned int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

unsigned int	gnl_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

unsigned int	gnl_strlcat(char *dst, char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	r;

	if (!src)
		return (gnl_strlen(dst));
	i = 0;
	j = 0;
	r = 0;
	while (dst[i])
		i++;
	while (src[r])
		r++;
	if (dstsize <= gnl_strlen(dst))
		r = dstsize + gnl_strlen(src);
	else
		r = gnl_strlen(dst) + gnl_strlen(src);
	while (src[j] && (i + 1) < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (r);
}
