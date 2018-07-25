/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:56:29 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/25 23:40:52 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	print_data(t_map_info *code, t_square *sol, int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < code->lns)
	{
		j = 0;
		while (j < code->col)
		{
			if ((i > sol->y - sol->size && i <= sol->y) &&
					(j > sol->x - sol->size && j <= sol->x))
			{
				ft_putchar(code->fch);
				j++;
			}
			else
			{
				tab[i][j] == 0 ? ft_putchar(code->och) : ft_putchar(code->ech);
				j++;
			}
		}
		i++;
		ft_putchar('\n');
	}
}
