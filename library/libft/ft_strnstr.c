/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:07:41 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/19 10:03:16 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	The strnstr() function locates the first occurrence of the 
//	null-terminated string needle in the string haystack, where not more than 
//	len characters are searched.  Characters that appear after a `\0' character
//	are not searched.

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		cnt;

	if (0 == ft_strlen((char *)needle))
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		cnt = 0;
		while (haystack[i + cnt] == needle[cnt] && needle[cnt])
		{
			if (i + cnt > len)
				return (NULL);
			cnt++;
		}
		if (!needle[cnt])
		{
			if (i + cnt > len)
				return (NULL);
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
