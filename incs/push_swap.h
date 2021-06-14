/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:33:17 by teppei            #+#    #+#             */
/*   Updated: 2021/06/14 16:53:02 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define ARGLIMIT 10000

typedef	struct s_dlst
{
	long			value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef	struct s_pair
{
	long			value;
	long			id;
}					t_pair;

typedef	struct s_ps
{
	t_dlst			*ans;
	t_pair			n[ARGLIMIT + 10];
	long			def[ARGLIMIT + 10];
	long			size;
	long			awant;
	long			bwant;
	long			ans_result;
	long			ans_turn;
	char			ans_next[5][10];
	bool			vflag;
	bool			cflag;
}					t_ps;

void	ps_dlst_clear(t_dlst *a);
void	ps_free_ps(t_dlst *a, t_dlst *b, t_ps *ps);
int		ps_puterror(t_dlst *a, t_dlst *b, t_ps *ps, int ret);
t_ps	*ps_init_ps(long argc, char **argv);
t_dlst	*ps_init_dlst(void);
char	**ps_get_option(long *argc, char **argv, t_ps *ps);

#endif