/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:25:22 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 17:18:49 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	*ft_strzero(char *s)
{
	unsigned int	i;

	i = 14;
	while (--i >= 0)
		s[i] = 0;
	return (s);
} */

static int	ft_hex_len(unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_putptr_pf(unsigned long long n, int i)
{
	char	*str;
	char	res[18];
	int		len;
	int		j;

	str = "0123456789abcdef";
	if (!(ft_hex_len(n)))
		return (-1);
	len = ft_hex_len(n);
	j = len + 2;
	if (!n)
		res[0] = '0';
	res[len] = '\0';
	while (n)
	{
		--len;
		res[len] = str[n % 16];
		n /= 16;
	}
	if (write (1, "0x", 2) != 2)
		return (-1);
	if (write (1, &res, j - 2) != j - 2)
		return (-1);
	return (i + j);
}
/* 
{
	char	*str;
	char	res[11];
	int		len;
	int		j;

	str = "0123456789abcdef";
	len = ft_hex_len(n);
	j = len;
	if (!n)
		res[0] = '0';
	res[len] = '\0';
	while (n)
	{
		len--;
		res[len] = str[n % 16];
		n /= 16;
	}
	if (write (1, &res, j) != j)
		return (-1);
	return (i + j);
}
 */
