/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_custom_ld_to_text.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:50:52 by aholster       #+#    #+#                */
/*   Updated: 2019/09/05 10:38:59 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

#include <fcntl.h>
static int	posiponent_loop(t_numlst **alst, short exponent)
{
	int fd;

	fd = open("./output", O_RDWR | O_APPEND | O_CREAT | O_TRUNC, S_IRWXU);
	while (exponent > 0)
	{
		dprintf(fd, "exponent is: |%hi|\n", exponent);
		// if (exponent > 16)
		// {
		// 	if (ft_lst_math_mul(alst, "65536") == -1)
		// 		return (-1);
		// 	exponent -= 16;
		// }
		// else if (exponent > 12)
		// {
		// 	if (ft_lst_math_mul(alst, "4096") == -1)
		// 		return (-1);
		// 	exponent -= 12;
		// }
		// else if (exponent > 8)
		// {
		// 	if (ft_lst_math_mul(alst, "256") == -1)
		// 		return (-1);
		// 	exponent -= 8;
		// }
		// else if (exponent > 4)
		// {
		// 	if (ft_lst_math_mul(alst, "16") == -1)
		// 		return (-1);
		// 	exponent -= 4;
		// }
		// else
		{
			if (ft_lst_math_mul(alst, "2") == -1)
				return (-1);
			exponent--;
		}
	}
	close (fd);
	return (1);
}

// static int	posiponent_loop(t_numlst **alst, short exponent)
// {
// 	const unsigned char			*expo_table[4] = {"2", "16", "256", "4096"};
// 	const unsigned char			prog_table[4] = {1, 4, 8, 12};
// 	unsigned char				cur_expo;

// 	while (exponent > 0)
// 	{
// 		if (exponent > 12)
// 			cur_expo = 3;
// 		else if (exponent > 8)
// 			cur_expo = 2;
// 		else if (exponent > 4)
// 			cur_expo = 1;
// 		else
// 			cur_expo = 0;
// 		if (ft_lst_math_mul(alst, expo_table[cur_expo]) == -1)
// 			return (-1);
// 		exponent -= prog_table[cur_expo];
// 	}
// 	return (1);
// }

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
	if (exponent == 16384) //generic abnormal number catcher
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
