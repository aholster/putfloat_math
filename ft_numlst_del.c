/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_del.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 21:34:18 by aholster       #+#    #+#                */
/*   Updated: 2019/07/27 19:02:26 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

void		ft_numlst_del(t_numlst **alst)
{
	t_numlst	*trail;
	t_numlst	*iterator;

	if (alst != NULL)
	{
		iterator = *alst;
		while (iterator != NULL)
		{
			trail = iterator;
			iterator = iterator->next;
			free(trail->mem);
			trail->mem_size = 0;
			free(trail);
		}
		*alst = NULL;
	}
}
