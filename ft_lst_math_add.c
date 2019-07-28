/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_math_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 19:00:45 by aholster       #+#    #+#                */
/*   Updated: 2019/07/28 20:38:26 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static void		ft_numlst_end(t_numlst **srclow, t_numlst **addlow)
{
	while ((*addlow)->next != NULL)
	{
		*addlow = (*addlow)->next;
		*srclow = (*srclow)->next;
	}
}

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

/*
**	welcome to the most obtuse function!
**	ft_lstlen is supposed to create the necesary structs to allow for simpler addition logic
** ie, making sure that 'source' is at least as big as 'target',
**	in both directions from decimal point
*/

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
	t_numlst	*srclow;
	t_numlst	*addlow;
	size_t		index;
	char		cache;

	if (ft_lstlen_match(source, addition) == 0)
		return (0);
	srclow = *source;
	addlow = addition;
	ft_numlst_end(&srclow, &addlow);
	while (addlow != NULL)
	{
		index = addlow->mem_size;
// presumably subfunc this up
		while (index != 0)
		{
			index--;
			if (addlow->mem[index] == '.')
				continue;
			cache = (addlow->mem[index] - '0') + (srclow->mem[index] - '0');
			if (cache > 9)
			{
				srclow->mem[index] = (cache % 10) + '0';
				cache -= (cache % 10);
				//trigger numerical addition to next character
			}
			else
				srclow->mem[index] = cache + '0';
		}
//end of subfunc
		srclow = srclow->prev;
		addlow = addlow->prev;
	}
//	ft_numlst_trim(source); trim list from mathematically useless structs
	return (1);
}
