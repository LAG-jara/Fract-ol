/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:07:13 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/11 19:09:56 by alajara-         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	res[12];
	int		len;

	len = ft_len(n);
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
	ft_putstr_fd(res, fd);
}
