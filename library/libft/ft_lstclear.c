/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:59:32 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/24 08:47:14 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters  lst: The address of a pointer to a node.
			del: The address of the function used to delete
			the content of the node.

External functs. free
Description Deletes and frees the given node and every
			successor of that node, using the function ’del’
			and free(3).
			Finally, the pointer to the list must be set to
			NULL.
*/
void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->nxt;
		(*lst)->val = -1;
		free(*lst);
		*lst = tmp;
	}
}
