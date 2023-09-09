/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:05:55 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/25 12:39:11 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chk(char c)
{
	int	r;

	r = 0;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		r = 1;
	if (c == '\f' || c == '\v')
		r = 1;
	return (r);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	isn;
	int	res;

	i = 0;
	isn = 1;
	res = 0;
	while (chk(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isn = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	res *= isn;
	return (res);
}
