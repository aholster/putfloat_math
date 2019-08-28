/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_tech.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 14:47:32 by aholster       #+#    #+#                */
/*   Updated: 2019/08/28 14:18:39 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_TECH_H
# define FLOAT_TECH_H

# include <stdio.h>
# include <float.h>

# include "./libft/libft.h"

typedef union			u_float
{
	long double			ld;
	unsigned short		byte[5];
	unsigned long long	llu;
}						t_float;

# define LSTBUF_SIZE 1

/*
**	LSTBUF_SIZE DOES NOT SUPPORT THE VALUE OF 3, OR smaller than 1
*/

typedef	struct			s_numlst
{
	char				*mem;
	size_t				mem_size;
	struct s_numlst		*next;
	struct s_numlst		*prev;
}						t_numlst;

void					longdouble_analyse(long double input);
char					*ft_custom_ld_to_text(long double input);

int						ft_numlst_to_str(char **str, const t_numlst *lst);

void					ft_numlst_del(t_numlst **alst);
size_t					ft_numlst_fwlen(const t_numlst *dec_lst);
size_t					ft_numlst_bwlen(const t_numlst *dec_lst);
t_numlst				*ft_numlst_newnode(void);
t_numlst				*ft_numlst_init(void);

int						ft_numlst_prefix(t_numlst *dec_lst,\
						unsigned short count);
int						ft_numlst_postfix(t_numlst *dec_lst,\
						unsigned short count);
int						ft_numlst_minsize(t_numlst *source, const t_numlst *target);
t_numlst				*ft_numlst_copy(const t_numlst *src);

int						ft_numlst_up_magni(t_numlst **ret, const t_numlst *source,\
						unsigned char magni);

int						ft_lst_math_add(t_numlst *source, t_numlst *addition);
int						ft_lst_math_mul(t_numlst **source,\
						unsigned short multiplier);
int						ft_lst_math_halve(t_numlst **source);

#endif
