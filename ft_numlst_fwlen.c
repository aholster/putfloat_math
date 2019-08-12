/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_fwlen.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/28 17:49:59 by aholster       #+#    #+#                */
/*   Updated: 2019/08/12 18:17:40 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

size_t			ft_numlst_fwlen(t_numlst *dec_lst)
{
	size_t		len;
	t_numlst	*lst;

	len = 0;
	lst = dec_lst;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
