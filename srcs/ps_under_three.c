/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_under_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:00:51 by teppei            #+#    #+#             */
/*   Updated: 2021/06/21 13:49:14 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

long	ps_judge_case(t_dlst *a, int f)
{
	long	x;
	long	y;
	long	z;

	x = a->next->value;
	y = a->next->next->value;
	z = a->next->next->next->value;
	if (f == 0 && (z == -1 || (z > x && x > y)))
		return (1);
	else if (f == 1 && (z == -1 || (z < x && x < y)))
		return (1);
	else if ((f == 0 && x > y && y > z) || (f == 1 && x < y && y < z))
		return (2);
	else if ((f == 0 && x > z && z > y) || (f == 1 && x < z && z < y))
		return (3);
	else if ((f == 0 && y > z && z > x) || (f == 1 && y < z && z < x))
		return (4);
	else if ((f == 0 && y > x && x > z) || (f == 1 && y < x && x < z))
		return (5);
	else
		return (0);
}

void	ps_set_ans(t_dlst *a, t_ps *ps, long c, char ab)
{
	int	s;
	int	r;
	int rr;

	s = SA;
	r = RA;
	rr = RRA;
	if (ab == 'b')
	{
		s = SB;
		r = RB;
		rr = RRB;
	}
	if (c == 1 || c == 2 || c == 4)
		ps_swap_addans(a, ps, s);
	if (c == 3 || c == 4)
		ps_rotate_addans(a, ps, r);
	if (c == 2 || c == 5)
		ps_reverse_r_addans(a, ps, rr);
}

void	ps_under_three(t_dlst *a, t_ps *ps, int f, char ab)
{
	if (!ps_sorted(a, f))
	{
		ps_set_ans(a, ps, ps_judge_case(a, f), ab);
		//ps_print_dlst(a);
	}
	//printf("awant: %ld\n", ps->awant);
}
