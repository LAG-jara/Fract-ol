/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:06:25 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/11 19:09:37 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The string representing the integer.
NULL if the allocation fails

Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/
static int	ft_cntr(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	if (!n)
		res[0] = '0';
	res[len] = '\0';
	while (n)
	{
		len--;
		res[len] = ft_cntr(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
