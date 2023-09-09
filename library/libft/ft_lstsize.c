/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:00:05 by alajara-          #+#    #+#             */
/*   Updated: 2022/10/19 08:39:03 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parameters lst: The beginning of the list.

Return value The length of the list

Description Counts the number of nodes in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int		r;
	t_list	*tmp;

	r = 0;
	tmp = lst;
	if (!tmp)
		return (r);
	while (++r && tmp->nxt)
	{
		tmp = tmp->nxt;
		if (tmp->nxt == lst->nxt)
			return (r);
	}
	return (r);
}
/*
int main()
{
	t_list	q;
	t_list	w;
	t_list	e;
	t_list	r;
	t_list	t;
	char	p;


	q.next = &w;
	w.next = &e;
	e.next = &r;
	r.next = &t;
	t.next = &q;
	p = ft_lstsize(&q) + '0';
	write(1, &p, 1);
}
*/