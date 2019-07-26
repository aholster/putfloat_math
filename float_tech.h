/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_tech.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 14:47:32 by aholster       #+#    #+#                */
/*   Updated: 2019/07/26 21:47:10 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_TECH
# define FLOAT_TECH

#include <stdio.h>
#include <float.h>

#include "libft.h"

typedef union			u_float
{
	long double			ld;
	unsigned short		byte[5];
}						t_float;

typedef struct			s_mathlst
{
	char				*mem;
	size_t				mem_size;
	struct s_mathlst	*next;
	struct s_mathlst	*prev;
}						t_mathlst;

#define LSTBUF_SIZE 16

typedef	struct			s_numlst
{
	char				*mem;
	size_t				mem_size;
//	unsigned			decimal:1;
	struct s_mathlst	*next;
}						t_numlst;

void	longdouble_analyse(long double input);
char	*custom_ld_to_text(long double input);

int		ft_numlst_to_str(char **str, t_numlst *lst);

void	ft_numlst_del(t_numlst	**alst);

#endif
