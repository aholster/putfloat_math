/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_math_mul.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 19:00:39 by aholster       #+#    #+#                */
/*   Updated: 2019/08/28 20:10:16 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static int	ft_mulcarry(t_numlst *cur, size_t index, char carry)
{
	char	*txt;

	txt = cur->mem;
	while (index > 0)
	{
		index--;
		if (txt[index] == '.')
			continue;
		carry += (txt[index] - '0');
		txt[index] = (carry % 10) + '0';
		carry /= 10;
		if (carry == 0)
			return (1);
	}
	if (cur->prev == NULL)
		if (ft_numlst_prefix(cur, 1) == -1)
			return (-1);
	return (ft_mulcarry(cur->prev, cur->prev->mem_size, carry));
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
			if (srcstart->mem[index] != '.')
			{
				cache = (srcstart->mem[index] - '0') * mult;
				srcstart->mem[index] = (cache % 10) + '0';
				if (cache > 9 && ft_mulcarry(srcstart, index, cache / 10) == -1)
					return (-1);
			}
			index++;
		}
		srcstart = srcstart->next;
	}
	return (1);
}

static int	ft_create_temp(t_numlst **temp, t_numlst *src, unsigned char mag)
{
	if (mag != 1)
	{
		*temp = ft_numlst_up_magni(src, mag);
		if (*temp == NULL)
			return (-1);
	}
	else
	{
		*temp = ft_numlst_copy(src);
		if (*temp == NULL)
			return (-1);
	}
	return (1);
}

int			ft_lst_math_mul(t_numlst **source, unsigned short multiply)
{
	char			mult;
	unsigned char	magnitude;
	t_numlst		*product;
	t_numlst		*temporary;

	magnitude = 1;
	product = ft_numlst_init();
	if (product == NULL)
		return (-1);
	while (multiply != 0)
	{
		mult = multiply % 10;
		if (mult != 0)
		{
			if (ft_create_temp(&temporary, *source, magnitude) == -1)
				return (-1);
			if (mult != 1 && ft_mul_structs(temporary, mult) == -1)
				return (-1);
			if (ft_lst_math_add(product, temporary) == -1)
				return (-1);
			ft_numlst_del(&temporary);
		}
		magnitude++;
		multiply /= 10;
	}
	ft_numlst_del(source);
	*source = product;
	return (1);
}
