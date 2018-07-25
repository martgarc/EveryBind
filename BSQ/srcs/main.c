/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:45:49 by nalonso           #+#    #+#             */
/*   Updated: 2018/07/25 22:51:12 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	solve_data(char *av)
{
	char		*inp;
	int			**tab;
	t_map_info	code;
	t_square	sol;

	inp = read_data(av);
	if (check_data(&code, inp))
	{
		tab = map_creator(inp, &code);
		sol = bsq(tab, &code);
		print_data(&code, &sol, tab);
		ft_free_tab(tab, code.lns);
	}
	else
	{
		write(2, "map error", 9);
		ft_putchar('\n');
	}
	free(inp);
}

void	solve_stdin(void)
{
	char		*inp;
	int			**tab;
	t_map_info	code;
	t_square	sol;

	inp = read_stdin();
	if (check_data(&code, inp))
	{
		tab = map_creator(inp, &code);
		sol = bsq(tab, &code);
		print_data(&code, &sol, tab);
		ft_free_tab(tab, code.lns);
	}
	else
		write(2, "map error", 9);
	free(inp);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			solve_data(av[i]);
			i += 1;
			if (i < ac)
				ft_putchar('\n');
		}
	}
	else
	{
		solve_stdin();
	}
	return (0);
}
