/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlst_up_magni.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/13 15:24:32 by aholster       #+#    #+#                */
/*   Updated: 2019/09/05 08:31:32 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static int	navigate_to_magni(t_numlst *product, const char digit, size_t index, unsigned char magni)
{
	char	*txt;

	while (1)
	{
		txt = product->mem;
		while (index > 0)
		{
			index--;
			if (txt[index] != '.')
			{
				magni--;
				if (magni == 0)
				{
					product->mem[index] = digit;
					return (1);
				}
			}
		}
		if (product->prev == NULL)
			if (ft_numlst_prefix(product, 1) == -1)
				return (-1);
		product = product->prev;
		index = product->mem_size;
	}
}

static int	ft_numlst_magni(t_numlst *product, const t_numlst *source, unsigned char magni)
{
	size_t		index;
	size_t		size;
	char		*txt;

	while (source != NULL)
	{
		index = 0;
		size = source->mem_size;
		txt = source->mem;
		while (index < size)
		{
			if (txt[index] != '.')
			{
				if (navigate_to_magni(product, txt[index], index, magni - 1) == -1)
					return (-1);
			}
			index++;
		}
		product = product->next;
		source = source->next;
	}
	return (1);
}

// static int	numlst_cleanup(const t_numlst *source, t_numlst *dst)
// {
// 	const t_numlst	*src_trav;
// 	t_numlst		*dst_trav;

// 	src_trav = source;
// 	dst_trav = dst;
// 	while (src_trav->next != NULL)
// 	{
// 		src_trav = src_trav->next;
// 		dst_trav = dst_trav->next;
// 	}
// 	if (dst_trav->next != NULL)
// 		while (dst_trav != NULL)
// 		{
// 			ft_bzero(dst_trav->mem, dst_trav->mem_size);
// 			dst_trav = dst_trav->next;
// 		}
// 	src_trav = source;
// 	dst_trav = dst;
// 	while (src_trav->prev != NULL)
// 	{
// 		src_trav = src_trav->prev;
// 		dst_trav = dst_trav->prev;
// 	}
// 	if (dst_trav->prev != NULL)
// 		while (dst_trav != NULL)
// 		{
// 			ft_bzero(dst_trav->mem, dst_trav->mem_size);
// 			dst_trav = dst_trav->prev;
// 		}
// }

static void	dst_cleanup(t_numlst *dst)
{
	t_numlst	*traveler;

	traveler = dst->next;
	while (traveler != NULL)
	{
		ft_bzero(traveler->mem, traveler->mem_size);
		traveler = traveler->next;
	}
	traveler = dst->prev;
	while (traveler != NULL)
	{
		ft_bzero(traveler->mem, traveler->mem_size);
		traveler = traveler->prev;
	}
	dst->mem[0] = '0';
	dst->mem[1] = '.';
	dst->mem[2] = '0';
}

int			ft_numlst_up_magni(const t_numlst *source, t_numlst *dst, unsigned char mag)
{
	t_numlst		*prod_trav;
	const t_numlst	*src_trav;

	dst_cleanup(dst);
	if (ft_numlst_minsize(dst, source) == -1)
		return (-1);
	src_trav = source;
	prod_trav = dst;
	while (src_trav->prev != NULL)
	{
		prod_trav = prod_trav->prev;
		src_trav = src_trav->prev;
	}
	if (ft_numlst_magni(prod_trav, src_trav, mag) == -1)
		return (-1);
	return (1);
}
// t_numlst	*ft_numlst_up_magni(const t_numlst *source,\
// 			const unsigned char magni)
// {
// 	t_numlst		*product;
// 	t_numlst		*prod_trav;
// 	const t_numlst	*src_trav;

// 	product = ft_numlst_init();
// 	if (product == NULL)
// 		return (NULL);
// 	if (ft_numlst_minsize(product, source) == -1)
// 	{
// 		ft_numlst_del(&product);
// 		return (NULL);
// 	}
// 	src_trav = source;
// 	prod_trav = product;
// 	while (src_trav->prev != NULL)
// 	{
// 		prod_trav = prod_trav->prev;
// 		src_trav = src_trav->prev;
// 	}
// 	if (ft_numlst_magni(prod_trav, src_trav, magni) == -1)
// 	{
// 		ft_numlst_del(&product);
// 		return (NULL);
// 	}
// 	return (product);
// }
