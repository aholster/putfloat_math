/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_math_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 19:00:45 by aholster       #+#    #+#                */
/*   Updated: 2019/07/28 19:03:21 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static int		ft_numlst_finddec(t_numlst *lst)
{
	size_t	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		if (lst->mem_size == 3)
			return (len);
		lst = lst->next;
	}
	return (-1);
}

static int		ft_lstlen_match(t_numlst **source, t_numlst *target)
{
	size_t	srclen;
	int		srczero;
	size_t	tarlen;
	int		tarzero;

	srclen = ft_numlst_len(*source);
	srczero = ft_numlst_finddec(*source);
	tarlen = ft_numlst_len(target);
	tarzero = ft_numlst_finddec(target);
	if (tarzero > srczero)
	{
		if (ft_numlst_prefix(source, tarzero - srczero) == 0)
			return (0);
		srclen += tarzero - srczero;
		srczero += tarzero - srczero;
	}
	if (tarlen > srclen)
	{
		if (ft_numlst_postfix(*source, tarlen - srclen) == 0)
			return (0);
		srclen += tarlen - srclen;
	}
	return (1);
}

int				ft_lst_math_add(t_numlst **source, t_numlst *addition)
{
	if (ft_lstlen_match(source, addition) == 0)
		return (0);
	while ()
	{

	}

//	ft_numlst_trim();
	return (1);
}
