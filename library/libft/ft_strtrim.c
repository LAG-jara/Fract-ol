/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:07:45 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/13 15:26:26 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
s1: The string to be trimmed.
set: The reference set of characters to trim.

The trimmed string.
NULL if the allocation fails.

Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_strlen((char *)s1);
	if (!*s1)
		return (ft_calloc(1, 1));
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strrchr(set, s1[j - 1]) && j > i)
		j--;
	r = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!r)
		return (NULL);
	while (j > i)
		r[k++] = s1[i++];
	r[k] = 0;
	return (r);
}
/*
 int main()
 {
	char *r;
	r = ft_strtrim("", "");
	ft_putnbr_fd(getpid(), 1);
	
	int l = 0;
	while(l == 0)
	usleep(10000000);
 }
 */