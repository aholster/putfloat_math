/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_del.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 21:34:18 by aholster       #+#    #+#                */
/*   Updated: 2019/07/26 22:04:23 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

void		ft_numlst_del(t_numlst **alst)
{
	t_numlst	*trail;

	if (alst != NULL)
	{
		while (*alst != NULL)
		{
			trail = *alst;
			*alst = (*alst)->next;
			free(trail->mem);
			trail->mem_size = 0;
			free(trail);
		}
		*alst = NULL;
	}
}
