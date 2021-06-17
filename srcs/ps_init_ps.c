/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:39:39 by teppei            #+#    #+#             */
/*   Updated: 2021/06/18 07:29:29 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

long	ps_atoi(char *str)
{
	long	n;
	long	num;
	long	ret;

	n = 1;
	if (*str == '-')
		n = -1;
	if (*str == '+' || *str == '-')
		str++;
	ret = 0;
	while (*str)
	{
		num = (*str++ - '0');
		ret = ret * 10 + n * num;
		if (ret > INT_MAX || ret < INT_MIN)
			exit(ps_puterror(NULL, NULL, NULL, 1));
	}
	return (ret);
}

void	ps_value_init(t_ps *ps, char **argv)
{
	int	i;

	i = -1;
	while (++i < ps->size)
	{
		ps->n[i].id = i;
		ps->n[i].value = ps_atoi(*argv++);
	}
	--i;
	while (++i < ARG_LIMIT)
	{
		ps->n[i].id = i;
		ps->n[i].value = 0;
	}
}

void	ps_dup_check(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit(ps_puterror(NULL, NULL, ps, 1));
	}
}

void	ps_convert_vid(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->size)
	{
		ps->def[i] = ps->n[i].value;
		ps->n[i].value = i + 1;
	}
}

t_ps	*ps_init_ps(long argc, char **argv)
{
	t_ps	*ps;
	int		i;

	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		exit(ps_puterror(NULL, NULL, NULL, 1));
	ps->a = NULL;
	ps->b = NULL;
	ps->awant = 0;
	ps->bwant = 0;
	ps->cmds = ps_init_dlst(ps);
	ps->size = argc - 1;
	i = -1;
	while (++i < 5)
		ft_memcpy(ps->ans_next[i], "\0\0\0\0\0\0\0\0", 8);
	ps->ans_result = 0;
	ps->ans_turn = 0;
	ps_value_init(ps, argv);
	ps_presort(ps->n, 0, ps->size - 1, SORT_VAL);
	ps_dup_check(ps);
	ps_convert_vid(ps);
	ps_presort(ps->n, 0, ps->size - 1, SORT_ID);
	return (ps);
}

/*
**  ---ps_value_init---
**  n[0] = (55, 0)
**  n[1] = (23, 1)
**  n[2] = (87, 2)
**  ---quick_sort(value)---
**  n[0] = (23, 1)
**  n[1] = (55, 0)
**  n[2] = (87, 2)
**	---convert_val_to_id---
**  n[0] = (0, 1) def[0] = 23
**  n[1] = (1, 0) def[1] = 55
**  n[2] = (2, 2) def[2] = 87
**  ---quick_sort(id)---
**  n[0] = (1, 0)
**  n[1] = (0, 1)
**  n[2] = (2, 2)
**  ---t_dlst *a---
**  a[0] = 1 <-55
**  a[1] = 0 <-23
**  a[2] = 2 <-87
*/
