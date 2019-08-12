/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:20:38 by aholster       #+#    #+#                */
/*   Updated: 2019/08/12 12:05:15 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float_tech.h"

int		main(int argc, char **argv)
{
	t_numlst	*addant;
	t_numlst	*source;
	char		*str;

	(void)argv;
	(void)argc;

	source = ft_numlst_init();
	if (source == NULL)
		return (-1);
	addant = ft_numlst_init();
	if (addant == NULL)
		return (-1);
	ft_numlst_prefix(addant, 1);
	addant->prev->mem[0] = '9';

	if (ft_numlst_to_str(&str, source) == -1)
		return (-1);
	printf("%s\n", str);
	ft_numlst_del(&source);
	return (0);
}

// int	main(void)
// {
// 	long double		num;

// 	printf("sizeof t_float %zu\n", sizeof(t_float));
// 	printf("sizeof long double %zu\n", sizeof(long double));
// 	printf("sizeof t_mathlst %zu\n", sizeof(t_numlst));

// 	num = -1.0;
// 	longdouble_analyse(num);
// 	num = 1.0;
// 	longdouble_analyse(num);
// 	num = 0.5;
// 	longdouble_analyse(num);
// 	num = -0.5;
// 	longdouble_analyse(num);

// 	num = LDBL_MAX;
// 	longdouble_analyse(num);
// 	num = LDBL_MIN;
// 	longdouble_analyse(num);

// 	num = 0.0;
// 	longdouble_analyse(num);
// 	num = 0.0 / 0.0;
// 	longdouble_analyse(num);
// 	num = 1.0 / 0.0;
// 	longdouble_analyse(num);

// 	num = 8.0;
// 	longdouble_analyse(num);

// 	t_float	num2;
// 	num2.ld = 0.0;
// 	num2.byte[4] = 0x7FFE;
// 	num2.byte[3] = (1 << 15);
// 	longdouble_analyse(num2.ld);

// 	num2.ld = 0.0;
// 	num2.byte[4] = 0xFFFE;
// 	longdouble_analyse(num2.ld);

// 	return (0);
// }
