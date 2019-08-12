/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_custom_ld_to_text.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:50:52 by aholster       #+#    #+#                */
/*   Updated: 2019/08/12 13:53:13 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

static unsigned long long	ft_llurev(unsigned long long num)
{
    unsigned char		counter;
    unsigned long long	reverse_num;

	counter = 63;
	reverse_num = num;
    num >>= 1;
    while (num != 0)
    {
       reverse_num <<= 1;
       reverse_num |= (num & 1);
       num >>= 1;
       counter--;
    }
    reverse_num <<= counter;
    return (reverse_num);
}

char						*ft_custom_ld_to_text(long double input)
{
	t_float			num;
	unsigned short	exponent;
	t_numlst		*lst;
	char			*str;

	num.ld = input;

unsigned long long numer = num.llu;
numer = ft_llurev(numer); //mantissa as unsigned long long,
printf("mantissa reverse as num is %llu\n", numer);
//divided by the right number is our "basic value"float, before exponents

	exponent = (num.byte[4] & 0x7FFF) - 16383;//exponent bias adjustment
	if (exponent == 16384)//generic abnormal number catcher
		return ("float is non-math-y");
	else
	{
		lst = ft_numlst_init();
		if (lst == NULL)
			return (NULL);
		/*
		** insert math functions here
		*/
	//		str = NULL;
		if (ft_numlst_to_str(&str, lst) == -1)
			return (NULL);
		ft_numlst_del(&lst);
	}
	return (str);
}
