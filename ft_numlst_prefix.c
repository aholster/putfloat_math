/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_prefix.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/28 18:00:02 by aholster       #+#    #+#                */
/*   Updated: 2019/07/28 19:29:43 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

int		ft_numlst_prefix(t_numlst **alst, unsigned short count)
{
	unsigned short	added;
	t_numlst		*new;

	added = 0;
	while (added < count)
	{
		new = ft_numlst_new();
		if (new == NULL)
			return (0);
		new->next = *alst;

		(*alst)->prev = new;
		
		*alst = new;
		added++;
	}
	return (1);	
}
