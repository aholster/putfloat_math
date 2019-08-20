/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_copy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 16:00:20 by aholster       #+#    #+#                */
/*   Updated: 2019/08/16 17:35:53 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static int	numlst_copy_backward(const t_numlst *travsrc, t_numlst *travprod)
{
	while (travsrc->prev != NULL)
	{
		if (ft_numlst_prefix(travprod, 1) == -1)
			return (-1);
		travsrc = travsrc->prev;
		travprod = travprod->prev;
		ft_memcpy(travprod->mem, travsrc->mem, travsrc->mem_size);
	}
	return (1);
}

static int	numlst_copy_forward(const t_numlst *travsrc, t_numlst *travprod)
{
	while (travsrc != NULL)
	{
		ft_memcpy(travprod->mem, travsrc->mem, travsrc->mem_size);
		if (travsrc->next != NULL)
			if (ft_numlst_postfix(travprod, 1) == -1)
				return (-1);
		travsrc = travsrc->next;
		travprod = travprod->next;
	}
	return (1);
}

t_numlst	*ft_numlst_copy(const t_numlst *src)
{
	t_numlst	*product;

	product = ft_numlst_init();
	if (product == NULL)
		return (NULL);
	if (numlst_copy_forward(src, product) == -1)
	{
		ft_numlst_del(&product);
		return (NULL);
	}
	if (numlst_copy_backward(src, product) == -1)
	{
		ft_numlst_del(&product);
		return (NULL);
	}
	return (product);
}
