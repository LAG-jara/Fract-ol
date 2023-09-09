/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:59:39 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/19 12:24:51 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters  lst: The node to free.
			del: The address of the function used to delete
			the content.

External functs. free

Description Takes as a parameter a node and frees the memory of
			the node’s content using the function ’del’ given
			as a parameter and free the node. The memory of
			’next’ must not be freed
*/

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	del(lst->val);
	free(lst);
}
