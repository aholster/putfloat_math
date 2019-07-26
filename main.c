/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:20:38 by aholster       #+#    #+#                */
/*   Updated: 2019/07/26 17:21:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

int	main(void)
{
	long double num;

	printf("sizeof t_float %zu\n", sizeof(t_float));
	printf("sizeof long double %zu\n", sizeof(long double));
	printf("sizeof t_mathlst %zu\n", sizeof(t_mathlst));

	num = -1.0;
	longdouble_analyse(num);
	num = 1.0;
	longdouble_analyse(num);
	num = 0.5;
	longdouble_analyse(num);
	num = -0.5;
	longdouble_analyse(num);
	
	num = LDBL_MAX;
	longdouble_analyse(num);
	num = LDBL_MIN;
	longdouble_analyse(num);

	num = 0.0;
	longdouble_analyse(num);
	num = 0.0/0.0;
	longdouble_analyse(num);
	num = 1.0/0.0;
	longdouble_analyse(num);

	num = 8.0;
	longdouble_analyse(num);

	t_float	num2;
	num2.ld = 0.0;
	num2.byte[4] = 0x7FFE;
	num2.byte[3] = (1 << 15);
	longdouble_analyse(num2.ld);

	num2.ld = 0.0;
	num2.byte[4] = 0xFFFE;
	longdouble_analyse(num2.ld);

	return (0);
}
