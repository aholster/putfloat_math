/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_to_str.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 21:33:22 by aholster       #+#    #+#                */
/*   Updated: 2019/07/26 22:23:11 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

int				ft_numlst_to_str(char **str, t_numlst *lst)
{
	size_t		len;
	t_numlst	*traveler;

	len = 0;
	traveler = lst;
	while (traveler != NULL)
	{
		len += traveler->mem_size;
		traveler = traveler->next;
	}
	*str = (char *)malloc(sizeof(char) * len + 1);
	if (*str == NULL)
		return (0);
	(*str)[len] = '\0';
	len = 0;
	while (lst != NULL)
	{
		ft_memcpy((*str) + len, lst->mem, lst->mem_size);
		len += lst->mem_size;
		lst = lst->next;
	}
	return (1);
}
