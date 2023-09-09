/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:07:23 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/24 10:42:36 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
s1: The prefix string.
s2: The suffix string

The new string.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	r = (char *)malloc(sizeof(char) * len);
	if (!r)
		return (NULL);
	ft_strlcpy(r, (char *)s1, (size_t)len);
	ft_strlcat(r, (char *)s2, (size_t)len);
	return (r);
}
