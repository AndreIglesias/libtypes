/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:07:03 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 16:59:44 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTYPES_H
# define LIBTYPES_H

/*
**	#define __SSIZE_T_TYPE		__SWORD_TYPE
**	__STD_TYPE __SSIZE_T_TYPE __ssize_t;
*/

/*
**	malloc
*/

# include <stdlib.h>

/*
**	Determine the wordsize from the preprocessor defines.
*/

# if defined __x86_64__ && !defined __ILP32__
#  define __WORDSIZE	64
# else
#  define __WORDSIZE	32
# endif

/*
**	Convenience types.
*/

typedef unsigned char							t_u_char;
typedef unsigned short int						t_u_short;
typedef unsigned int							t_u_int;
typedef unsigned long int						t_u_long;

# if __WORDSIZE == 64
typedef signed long int							t_int64_t;
typedef unsigned long int						t_uint64_t;
# else
__extension__ typedef signed long long int		t_int64_t;
__extension__ typedef unsigned long long int	t_uint64_t;
# endif

/*
**	quad_t is also 64 bits.
*/

# if __WORDSIZE == 64
typedef long int								t_quad_t;
typedef unsigned long int						t_u_quad_t;
# else
__extension__ typedef long long int				t_quad_t;
__extension__ typedef unsigned long long int	t_u_quad_t;
# endif

/*
**	Largest integral types.
*/

# if __WORDSIZE == 64
typedef long int								t_intmax_t;
typedef unsigned long int						t_uintmax_t;
# else
__extension__ typedef long long int				t_intmax_t;
__extension__ typedef unsigned long long int	t_uintmax_t;
# endif

typedef struct s_trie
{
	t_u_char			children;
	t_u_char			end;
	struct s_trie		**map;
	char				*value;
}	t_trie;

#endif
