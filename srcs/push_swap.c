/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:32:10 by teppei            #+#    #+#             */
/*   Updated: 2021/06/14 15:41:25 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ps_puterror(char *s, char **p, int ret)
{
	if (s)
		free(s);
	if (p)
		ft_free_ptr(p);
	ft_putstr_fd("Error\n", 2);
	return (ret);
}

int	main(int argc, char **argv)
{
	//int	*a;
	//int	*b;
	int	listsize;

	listsize = argc - 1;
	if (listsize < 1)
		return (1);
	ft_putstrs_fd(argv, '\n', 1);
	if (ft_ptrdigit(++argv) == 0)
		return (ps_puterror(NULL, NULL, 1));
	printf("listsize: %d\n", listsize);
	(void)argv;
	return (0);
}
