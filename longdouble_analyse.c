/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   longdouble_analyse.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 14:45:22 by aholster       #+#    #+#                */
/*   Updated: 2019/07/27 18:58:53 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static void	put_annotation(unsigned short mexponent, long double input)
{
	char	*floatret;

	printf("\n");
	printf(" hex:\t%LA\n", input);
	printf(" Float:\t%Le\n", input);
	printf(" Raw exponent: %hu, Bias adjusted exponent: %d\n",\
	mexponent, mexponent - 16383);
	floatret = ft_custom_ld_to_text(input);
	printf(" Our Float Returns:\t%s\n", floatret);
/*
**	printf(" Norm Float:\t%Lf\n", input);
*/
	printf("\n");
}

void		longdouble_analyse(long double input)
{
	t_float			num;
	size_t			index;
	size_t			subdex;
	unsigned short	mexponent;

	num.ld = input;
	index = 5;
	mexponent = num.byte[4] & 0x7FFF;
	printf("\033[0;34mStarting Float analysis...\033[0;00m\n");
	printf("┌Sign Bit\n");
	printf("|┌Exponent...  ┐ ┌'Integer' bit\n");
	printf("||             | |┌Mantissa...%56s\n", "┐");
	while (index > 0)
	{
		index--;
		subdex = 16;
		while (subdex > 0)
		{
			subdex--;
			if (((num.byte[index] >> subdex) & 1) == 1)
				write(1, "1", 1);
			else
				write(1, "0", 1);
		}
		write(1, " ", 1);
	}
	put_annotation(mexponent, input);
}
