/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:32:10 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 22:41:56 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_print_dlst(t_dlst *a)
{
	t_dlst	*tmp;
	int		i;

	tmp = a->next;
	i = 1;
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
		printf("[%ld]: %ld\n", ps->n[i].id, ps->n[i].value);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;
	t_dlst	*a;
	t_dlst	*b;

	if (argc < 2 || ARGLIMIT < argc - 1)
		return (1);
	if (ft_ptrdigit(++argv) == 0)
		return (ps_puterror(NULL, NULL, NULL, 1));
	ps = ps_init_ps(argc, argv);
	a = ps_init_dlst();
	b = ps_init_dlst();
	ps_print_ps_vid(ps);
	ps_print_dlst(a);
	ps_print_dlst(b);
	ps_free_ps(a, b, ps);
	return (0);
}
