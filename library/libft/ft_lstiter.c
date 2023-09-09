/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:59:44 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/19 08:53:53 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters  lst: The address of a pointer to a node.
			f: The address of the function used to iterate on
			the list.

Description Iterates the list ’lst’ and applies the function
			’f’ on the content of each node.
*/

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->val);
		lst = lst->nxt;
	}
}
