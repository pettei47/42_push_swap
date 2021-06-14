/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:32:10 by teppei            #+#    #+#             */
/*   Updated: 2021/06/14 16:28:41 by teppei           ###   ########.fr       */
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

t_ps	*ps_init_ps(void)
{
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		listsize;
	t_ps	*ps;
	t_dlst	*a;
	t_dlst	*b;

	listsize = argc - 1;
	if (listsize < 1 || ARGLIMIT < listsize)
		return (1);
	if (ft_ptrdigit(++argv) == 0)
		return (ps_puterror(NULL, NULL, NULL, 1));
	ps = ps_init_ps();
	a = ps_init_dlst();
	b = ps_init_dlst();
	return (0);
}
