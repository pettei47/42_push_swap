/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:32:10 by teppei            #+#    #+#             */
/*   Updated: 2021/06/21 16:13:29 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_print_dlst(t_dlst *a, char *str)
{
	t_dlst	*tmp;
	int		i;

	tmp = a->next;
	i = 1;
	printf("%s\n", str);
	while (tmp->value != -1)
	{
		printf("[%d]: %ld\n", i++, tmp->value);
		tmp = tmp->next;
	}
}

void	ps_cmd_putout(long cmd)
{
	if (cmd == SA)
		write(1, "sa", 2);
	if (cmd == SB)
		write(1, "sb", 2);
	if (cmd == SS)
		write(1, "ss", 2);
	if (cmd == PA)
		write(1, "pa", 2);
	if (cmd == PB)
		write(1, "pb", 2);
	if (cmd == RA)
		write(1, "ra", 2);
	if (cmd == RB)
		write(1, "rb", 2);
	if (cmd == RR)
		write(1, "rr", 2);
	if (cmd == RRA)
		write(1, "rra", 3);
	if (cmd == RRB)
		write(1, "rrb", 3);
	if (cmd == RRR)
		write(1, "rrr", 3);
}

void	ps_cmds_print(t_dlst *cmds)
{
	t_dlst	*tmp;

	tmp = cmds->next;
	while (tmp->value != -1)
	{
		ps_cmd_putout(tmp->value);
		tmp = tmp->next;
		ft_putstr_fd("\n", 1);
	}
}

void	push_swap(t_dlst *a, t_dlst *b, t_ps *ps)
{
	if (ps->size < 4)
		ps_under_three(a, ps, 0, 'a');
	else
		ps_over_three(a, b, ps);
	ps_cmds_shorten(ps->cmds);
	return ;
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2 || ARG_LIMIT < argc - 1)
		return (1);
	if (ft_ptrdigit(++argv) == 0)
		return (ps_puterror(NULL, NULL, NULL, 1));
	ps = ps_init_ps(argc, argv);
	ps->a = ps_set_a(ps);
	ps->b = ps_init_dlst(ps);
	if (ps_sorted(ps->a, 0))
		return (0);
	push_swap(ps->a, ps->b, ps);
	ps_cmds_print(ps->cmds);
	ps_free_ps(ps->a, ps->b, ps);
	exit (0);
}
