/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:14:08 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 17:18:57 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_putnbr_pf(int n, int i)
{
	char	res[12];
	int		len;
	int		j;

	len = ft_len(n);
	j = len;
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
	if (write (1, &res, j) != j)
		return (-1);
	return (i + j);
}

// For unsigned int we don't need to check negatives. 

static int	ft_uns_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putunsi_pf(unsigned int n, int i)
{
	char	res[11];
	int		len;
	int		j;

	len = ft_uns_len(n);
	j = len;
	if (!n)
		res[0] = '0';
	res[len] = '\0';
	while (n)
	{
		len--;
		res[len] = n % 10 + '0';
		n /= 10;
	}
	if (write (1, &res, j) != j)
		return (-1);
	return (i + j);
}
