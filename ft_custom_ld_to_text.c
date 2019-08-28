/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_custom_ld_to_text.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:50:52 by aholster       #+#    #+#                */
/*   Updated: 2019/08/28 18:22:55 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

char	*ft_custom_ld_to_text(long double input)
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
		if (exponent < 0)
			while (exponent != 0)
			{
				if (ft_lst_math_halve(&lst) == -1)
				{
					ft_numlst_del(&lst);
					return (NULL);
				}
				exponent++;
			}
		else
			while (exponent > 0)
			{
				if (ft_lst_math_mul(&lst, 2) == -1)
				{
					ft_numlst_del(&lst);
					return (NULL);
				}
				exponent--;
			}
		if (ft_numlst_to_str(&str, lst) == -1)
			return (NULL);
		ft_numlst_del(&lst);
	}
	return (str);
}
