/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_inline_copy.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 14:16:02 by aholster       #+#    #+#                */
/*   Updated: 2019/08/29 14:34:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static int	numlst_copy_backward(const t_numlst *travsrc, t_numlst *travprod)
{
	while (travsrc->prev != NULL)
	{
		if (travprod->prev == NULL)
			if (ft_numlst_prefix(travprod, 1) == -1)
				return (-1);
		travsrc = travsrc->prev;
		travprod = travprod->prev;
		ft_memcpy(travprod->mem, travsrc->mem, travsrc->mem_size);
	}
	if (travprod != NULL && travprod->prev != NULL)
		while (travprod != NULL)
		{
			ft_bzero(travprod->mem, travprod->mem_size);
			travprod = travprod->prev;
		}
	return (1);
}

static int	numlst_copy_forward(const t_numlst *travsrc, t_numlst *travprod)
{
	while (travsrc != NULL)
	{
		ft_memcpy(travprod->mem, travsrc->mem, travsrc->mem_size);
		if (travsrc->next != NULL && travprod->next == NULL)
			if (ft_numlst_postfix(travprod, 1) == -1)
				return (-1);
		travsrc = travsrc->next;
		travprod = travprod->next;
	}
	if (travprod != NULL && travprod->next != NULL)
		while (travprod != NULL)
		{
			ft_bzero(travprod->mem, travprod->mem_size);
			travprod = travprod->next;
		}
	return (1);
}

int			ft_numlst_inline_copy(const t_numlst *source, t_numlst *lst)
{
	if (numlst_copy_backward(source, lst) == -1)
		return (-1);
	if (numlst_copy_forward(source, lst) == -1)
		return (-1);
	return (1);
}
