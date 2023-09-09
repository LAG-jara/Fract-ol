/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:09:22 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 17:10:46 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign. */

static int	ft_checkndo(const char *a, int i, va_list lst)
{
	if (*a == 'c')
		i = ft_putchr_pf(va_arg(lst, int), i);
	else if (*a == 's')
		i = ft_putstr_pf(va_arg(lst, char *), i);
	else if (*a == 'p')
		i = ft_putptr_pf(va_arg(lst, unsigned long long), i);
	else if (*a == 'd' || *a == 'i')
		i = ft_putnbr_pf(va_arg(lst, int), i);
	else if (*a == 'u')
		i = ft_putunsi_pf(va_arg(lst, unsigned int), i);
	else if (*a == 'x')
		i = ft_puthex_pf(va_arg(lst, unsigned int), i);
	else if (*a == 'X')
		i = ft_puthexup_pf(va_arg(lst, unsigned int), i);
	else
		i = ft_putchr_pf(*a, i);
	return (i);
}

int	ft_printf(const char *a, ...)
{
	int		i;
	va_list	lst;

	va_start(lst, a);
	i = 0;
	while (*a && i != -1)
	{
		if (*a == '%')
			i = ft_checkndo(++a, i, lst);
		else
			i = ft_putchr_pf(*a, i);
		++a;
	}
	return (i);
}

/* int main()
{
	//char a = 'd'; 
	if (ft_printf("%p\n", (void*)-14523) == printf("%p\n", (void*)-14523))
		printf("SUCCESS\n");
	else
		printf("FAILURE\n");
}
 */
