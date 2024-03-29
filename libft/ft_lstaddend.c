/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 13:07:44 by aholster       #+#    #+#                */
/*   Updated: 2019/04/06 17:58:34 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddend(t_list **lst, t_list *new)
{
	t_list *internal;

	if (*lst == NULL)
	{
		*lst = new;
		return (new);
	}
	internal = *lst;
	while (internal->next != NULL)
	{
		internal = internal->next;
	}
	internal->next = new;
	return (new);
}
