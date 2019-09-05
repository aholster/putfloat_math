/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_custom_ld_to_text.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:50:52 by aholster       #+#    #+#                */
/*   Updated: 2019/09/05 12:09:20 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

// static int	posiponent_loop(t_numlst **alst, short exponent)
// {
// 	while (exponent > 0)
// 	{
// 		if (exponent > 28)
// 		{
// 			if (ft_lst_math_mul(alst, "268435456") == -1)
// 				return (-1);
// 			exponent -= 28;
// 		}
// 		else if (exponent > 24)
// 		{
// 			if (ft_lst_math_mul(alst, "16777216") == -1)
// 				return (-1);
// 			exponent -= 24;
// 		}
// 		else if (exponent > 20)
// 		{
// 			if (ft_lst_math_mul(alst, "1048576") == -1)
// 				return (-1);
// 			exponent -= 20;
// 		}
// 		else if (exponent > 16)
// 		{
// 			if (ft_lst_math_mul(alst, "65536") == -1)
// 				return (-1);
// 			exponent -= 16;
// 		}
// 		else if (exponent > 12)
// 		{
// 			if (ft_lst_math_mul(alst, "4096") == -1)
// 				return (-1);
// 			exponent -= 12;
// 		}
// 		else if (exponent > 8)
// 		{
// 			if (ft_lst_math_mul(alst, "256") == -1)
// 				return (-1);
// 			exponent -= 8;
// 		}
// 		else if (exponent > 4)
// 		{
// 			if (ft_lst_math_mul(alst, "16") == -1)
// 				return (-1);
// 			exponent -= 4;
// 		}
// 		else
// 		{
// 			if (ft_lst_math_mul(alst, "2") == -1)
// 				return (-1);
// 			exponent--;
// 		}
// 	}
// 	return (1);
// }

static int	posiponent_loop(t_numlst **alst, short exponent)
{
	const char					*expo_table[5] = {"2", "16", "256", "65536", "268435456"};
	const unsigned char			prog_table[5] = {1, 4, 8, 16, 28};
	unsigned char				cur_expo;

	while (exponent > 0)
	{
		if (exponent >= 28)
			cur_expo = 4;
		else if (exponent >= 16)
			cur_expo = 3;
		else if (exponent >= 8)
			cur_expo = 2;
		else if (exponent >= 4)
			cur_expo = 1;
		else
			cur_expo = 0;
		if (ft_lst_math_mul(alst, expo_table[cur_expo]) == -1)
			return (-1);
		exponent -= prog_table[cur_expo];
	}
	return (1);
}

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
	{
		if (posiponent_loop(alst, exponent) == -1)
		{
			ft_numlst_del(alst);
			return (-1);
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
