/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:32:10 by teppei            #+#    #+#             */
/*   Updated: 2021/06/14 17:36:09 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_dlst_clear(t_dlst *a)
{
	t_dlst	*tmp;

	a->prev->next = NULL;
	while (a)
	{
		tmp = a->next;
		a->prev = NULL;
		free(a);
		a = tmp;
	}
}

void	ps_free_ps(t_dlst *a, t_dlst *b, t_ps *ps)
{
	if (a)
		ps_dlst_clear(a);
	if (b)
		ps_dlst_clear(b);
	if (ps)
	{
		ps_dlst_clear(ps->ans);
		free(ps);
	}
}

int	ps_puterror(t_dlst *a, t_dlst *b, t_ps *ps, int ret)
{
	ps_free_ps(a, b, ps);
	ft_putstr_fd("Error\n", 2);
	return (ret);
}

t_dlst	*ps_init_dlst(void)
{
	t_dlst	*dl;

	dl = (t_dlst *)malloc(sizeof(t_dlst));
	if (!dl)
		exit(ps_puterror(NULL, NULL, NULL, 1));
	dl->value = -1;
	dl->next = dl;
	dl->prev = dl;
	return (dl);
}

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
	ps_print_dlst(a);
	ps_print_dlst(b);
	//ps_free_ps(a, b, ps);
	return (0);
}
