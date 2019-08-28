/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_custom_ld_to_text.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:50:52 by aholster       #+#    #+#                */
/*   Updated: 2019/08/28 20:07:27 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static int	exponent_calculation(t_numlst **alst, short exponent)
{
	if (exponent < 0)
		while (exponent != 0)
		{
			if (ft_lst_math_halve(alst) == -1)
			{
				ft_numlst_del(alst);
				return (-1);
			}
			exponent++;
		}
	else
		while (exponent > 0)
		{
			if (exponent > 12)
			{
				if (ft_lst_math_mul(alst, 4096) == -1)
				{
					ft_numlst_del(alst);
					return (-1);
				}
				exponent -= 12;
			}
			else if (exponent > 8)
			{
				if (ft_lst_math_mul(alst, 256) == -1)
				{
					ft_numlst_del(alst);
					return (-1);
				}
				exponent -= 8;
			}
			else if (exponent > 4)
			{
				if (ft_lst_math_mul(alst, 16) == -1)
				{
					ft_numlst_del(alst);
					return (-1);
				}
				exponent -= 4;
			}
			else
			{
				if (ft_lst_math_mul(alst, 2) == -1)
				{
					ft_numlst_del(alst);
					return (-1);
				}
				exponent--;
			}
		}
	return (1);
}

char		*ft_custom_ld_to_text(long double input)
{
	t_float				num;
	short				exponent;
	t_numlst			*lst;
	char				*str;

	num.ld = input;
	exponent = (num.byte[4] & 0x7FFF) - 16383;//exponent bias adjustment
	if (exponent == 16384)//generic abnormal number catcher
		return ("float is non-math-y");
	else
	{
		lst = ft_mantissa_to_numlst(num.llu);
		if (lst == NULL)
			return (NULL);
		if (exponent_calculation(&lst, exponent) == -1)
			return (NULL);
		if (ft_numlst_to_str(&str, lst) == -1)
		{
			ft_numlst_del(&lst);
			return (NULL);
		}
		ft_numlst_del(&lst);
	}
	return (str);
}
