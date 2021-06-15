/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:33:17 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 22:41:41 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define ARGLIMIT 10000

typedef enum e_cmd
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}					t_cmd;

typedef	struct s_dlst
{
	long			value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef	struct s_vid
{
	long			value;
	long			id;
}					t_vid;

typedef	struct s_ps
{
	t_dlst			*ans;
	t_vid			n[ARGLIMIT + 10];
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

#endif