/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_postfix.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/28 17:59:50 by aholster       #+#    #+#                */
/*   Updated: 2019/07/28 19:29:10 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

int		ft_numlst_postfix(t_numlst *lst, unsigned short count)
{
	unsigned short	added;
	t_numlst		*new;

	added = 0;
	while (lst->next != NULL)
		lst = lst->next;
	while (added < count)
	{
		new = ft_numlst_new();
		if (new == NULL)
			return (0);
		lst->next = new;

		new->prev = lst;
		
		lst = new;
		added++;
	}
	return (1);
}
