/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_math_mul.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 19:00:39 by aholster       #+#    #+#                */
/*   Updated: 2019/08/12 18:19:50 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static int	ft_numlst_magnitude(t_numlst **ret, t_numlst *source,\
			unsigned char magnitude)
{
	t_numlst	*product;
	size_t		len;

	product = ft_numlst_init();
	if (product == NULL)
		return (-1);
	len = ft_numlst_fwlen(source);
	if (len > 1)
		if (ft_numlst_postfix(product, len - 1) == -1)
			return (-1);
	while ()
	{
		
	}
	return (1);
}

static int	ft_struct_mulcarry(t_numlst *cur, size_t index, char carry)
{
	char	*txt;

	txt = cur->mem;
	while (index > 0)
	{
		index--;
		if (txt[index] == '.')
			continue;
		carry += (txt[index] - '0');
		txt[index] = carry % 10;
		carry /= 10;
		if (carry == 0)
			return (1);
	}
	if (cur->prev == NULL)
		if (ft_numlst_prefix(cur, 1) == -1)
			return (-1);
	return (ft_struct_mulcarry(cur->prev, cur->prev->mem_size, carry));
}

static int	ft_mul_structs(t_numlst *source, char mult)
{
	size_t			index;
	size_t			size;
	t_numlst		*srcstart;
	unsigned char	cache;

	srcstart = source;
	while (srcstart->prev != NULL)
		srcstart = srcstart->prev;
	while (srcstart != NULL)
	{
		size = srcstart->mem_size;
		index = 0;
		while (index < size)
		{
			if (srcstart->mem[index] == '.')
				continue;
			cache = (srcstart->mem[index] - '0') * mult;
			srcstart->mem[index] = cache % 10;
			if (cache > 9)
				if (ft_struct_mulcarry(srcstart, index, cache / 10) == -1)
					return (-1);
			index++;
		}
		srcstart = srcstart->next;
	}
	return (1);
}

int			ft_lst_math_mul(t_numlst **source, unsigned short multiplier)
{
	char			mult;
	unsigned char	magnitude;
	t_numlst		*product;
	t_numlst		*temporary;

	magnitude = 1;
	product = ft_numlst_init();
	if (product == NULL)
		return (-1);
	while (multiplier != 0)
	{
		mult = multiplier % 10;
		if (magnitude != 1 && ft_numlst_magnitude(&temporary, *source, magnitude) == -1)
			return (-1);
		if (mult != 1 && ft_mul_structs(temporary, mult) == -1)
			return (-1);
		if (ft_numlst_math_add(product, temporary) == -1)
			return (-1);
		magnitude++;
		multiplier /= 10;
	}
	ft_numlst_del(source);
	*source = product;
	return (1);
}
