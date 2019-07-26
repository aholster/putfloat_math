/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_custom_ld_to_text.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:50:52 by aholster       #+#    #+#                */
/*   Updated: 2019/07/26 22:25:10 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static t_numlst			*init_lst(void)
{
	t_numlst	*node;

	node = (t_numlst *)malloc(sizeof(t_numlst));
	if (node == NULL)
		return (NULL);
	node->mem = (char *)malloc(sizeof(char) * 3);
	if (node->mem == NULL)
	{
		free(node);
		return (NULL);
	}
//	node->mem = (char[3]){'0', '.', '0'};
	node->mem[0] = '0';
	node->mem[1] = '.';
	node->mem[2] = '0';
	node->mem_size = 3;
	node->next = NULL;
	return (node);
}

char					*ft_custom_ld_to_text(long double input)
{
	t_float			num;
	unsigned short	exponent;
	t_numlst		*lst;
	char			*str;

	num.ld = input;
	exponent = (num.byte[4] & 0x7FFF) - 16383;
	if (exponent == 16384)
		return ("nan/exception");
	else
	{
		lst = init_lst();
		if (lst == NULL)
			return (NULL);
//		str = NULL;
		if (ft_numlst_to_str(&str, lst) == 0)
			return (NULL);
		ft_numlst_del(&lst);
	}
	return (str);
}
