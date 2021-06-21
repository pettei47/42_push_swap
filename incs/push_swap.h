/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:33:17 by teppei            #+#    #+#             */
/*   Updated: 2021/06/21 13:49:24 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define ARG_LIMIT		5000
# define SORT_VAL		1
# define SORT_ID		0
# define LIMIT_UNDER3	2
# define LIMIT_OVER3	30
# define CMD_NUM		11
# define SORTSIZE		3
# define STACK_WIDTH	18
# define INFO_WIDTH		8

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
	t_dlst			*a;
	t_dlst			*b;
	t_dlst			*cmds;
	t_vid			n[ARG_LIMIT + 10];
	long			def[ARG_LIMIT + 10];
	long			size;
	long			awant;
	long			bwant;
	long			ans_result;
	long			ans_turn;
	char			ans_next[5][10];
	bool			vflag;
	bool			cflag;
}					t_ps;

typedef struct s_sort
{
	long			max_turn;
	long			turn;
	long			tmp[LIMIT_OVER3+ 10];
	long			ans[LIMIT_OVER3 + 10];
	long			pre;
	long			awant;
	long			size;
	long			fin;
}					t_sort;

int		ps_puterror(t_dlst *a, t_dlst *b, t_ps *ps, int ret);
void	ps_dlst_clear(t_dlst *a);
void	ps_free_ps(t_dlst *a, t_dlst *b, t_ps *ps);
t_ps	*ps_init_ps(long argc, char **argv);
t_dlst	*ps_init_dlst(t_ps *ps);
t_dlst	*ps_set_a(t_ps *ps);
void	ps_dlst_addback(t_ps *ps, t_dlst *dlst, long value);
void	ps_presort(t_vid n[], long left, long right, long flag);
bool	ps_sorted(t_dlst *a, int f);
void	ps_under_three(t_dlst *a, t_ps *ps, int f, char ab);
void	ps_ans_update(long turn, t_sort *t, long i);
bool	ps_skip_check(long command, t_sort *t);
bool	ps_change_dlst(t_dlst *a, t_dlst *b, long cmd, bool exec);
void	ps_update_ans_dlst(t_ps *ps, t_dlst *a, t_dlst *b, t_sort *t);
void	ps_cmds_shorten(t_dlst *cmds);
void	ps_over_three(t_dlst *a, t_dlst *b, t_ps *ps);
long	ps_dlst_size(t_dlst *b);

bool	ps_swap(t_dlst *a);
bool	ps_push(t_dlst *a, t_dlst *b);
bool	ps_rotate(t_dlst *a);
bool	ps_reverse_rotate(t_dlst *a);
bool	ps_ss(t_dlst *a, t_dlst *b);
bool	ps_rr(t_dlst *a, t_dlst *b);
bool	ps_rrr(t_dlst *a, t_dlst *b);

bool	ps_push_addans(t_dlst *a, t_dlst *b, t_ps *ps, long cmd);
bool	ps_rotate_addans(t_dlst *a, t_ps *ps, long cmd);
bool	ps_reverse_r_addans(t_dlst *a, t_ps *ps, long cmd);
bool	ps_swap_addans(t_dlst *a, t_ps *ps, long cmd);

void	ps_push_btoa(t_dlst *a, t_dlst *b, t_ps *ps);
void	ps_print_dlst(t_dlst *a, char *str);

#endif
