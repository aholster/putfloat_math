/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/26 17:20:38 by aholster       #+#    #+#                */
/*   Updated: 2019/08/28 16:12:55 by aholster      ########   odam.nl         */
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
	source->mem[0] = '7';
//	ft_numlst_prefix(addant, 4);
//	addant->prev->prev->mem[0] = '9';
	addant->mem[0] = '9';
	printf("add returned %d\n", ft_lst_math_add(source, addant));
	ft_numlst_del(&addant);
	if (ft_numlst_to_str(&str, source) == -1)
		return (-1);
	printf("text:%s\n", str);

	printf("mult returned: %d\n", ft_lst_math_mul(&source, 65535));
	free(str);
	if (ft_numlst_to_str(&str, source) == -1)
		return (-1);

	printf("halve returned: %d\n", ft_lst_math_halve(&source));
	free(str);
	if (ft_numlst_to_str(&str, source) == -1)
		return (-1);

	printf("halve returned: %d\n", ft_lst_math_halve(&source));
	free(str);
	if (ft_numlst_to_str(&str, source) == -1)
		return (-1);

	ft_numlst_del(&source);
	free(str);
	return (0);
}
