/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:06:29 by alajara-          #+#    #+#             */
/*   Updated: 2022/09/22 14:50:08 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	The memchr() function locates the first occurrence of c (converted to an 
//	unsigned char) in string s.
//	The memchr() function returns a pointer to the byte located, or NULL if no
//	such byte exists within n bytes.
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
