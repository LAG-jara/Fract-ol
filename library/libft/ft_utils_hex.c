/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:01:08 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 17:18:37 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthexup_pf(unsigned int n, int i)
{
	char	*str;
	char	res[11];
	int		len;
	int		j;

	str = "0123456789ABCDEF";
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

int	ft_puthex_pf(unsigned int n, int i)
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
