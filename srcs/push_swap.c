/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:32:10 by teppei            #+#    #+#             */
/*   Updated: 2021/06/18 07:53:28 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_print_dlst(t_dlst *a)
{
	t_dlst	*tmp;
	int		i;

	tmp = a->next;
	i = 1;
	printf("dlst\n");
	while (tmp->value != -1)
	{
		printf("[%d]: %ld\n", i++, tmp->value);
		tmp = tmp->next;
	}
}

void	ps_print_ps_vid(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->size)
		printf("[%d]: %ld\n", i, ps->def[i]);
}

void	push_swap(t_dlst *a, t_dlst *b, t_ps *ps)
{
	if (ps->size < 7)
		ps_less_seven(a, b, ps);
	//else
	//	ps_over_six(a, b, ps);
	ps_cmds_shorten(ps->cmds);
	ps_print_dlst(ps->cmds);
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
	if (ps_sorted(ps->a))
		return (0);
	push_swap(ps->a, ps->b, ps);
	ps_free_ps(ps->a, ps->b, ps);
	exit (0);
}
