/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:52:19 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 17:19:06 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchr_pf(int c, int i)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (++i);
}

static size_t	ft_strl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_putstr_pf(char *str, int i)
{
	int	j;

	j = 0;
	if (!str)
		str = "(null)";
	j = ft_strl(str);
	if (write (1, str, j) != j)
		return (-1);
	return (i + j);
}
