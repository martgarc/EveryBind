/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:10:43 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/25 23:20:45 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int			give_value(int i, int j, int **sum, t_square *sol)
{
	int min;
	int max;

	min = 0;
	max = sol->size;
	if (sum[i - 1][j - 1] < sum[i - 1][j])
		min = sum[i - 1][j - 1];
	else
		min = sum[i - 1][j];
	if (sum[i][j - 1] < min)
		min = sum[i][j - 1];
	sum[i][j] = min + 1;
	if (sum[i][j] > max)
	{
		max = sum[i][j];
		sol->size = sum[i][j];
		sol->y = i;
		sol->x = j;
	}
	return (sum[i][j]);
}

int			**fill(int **tab, int **sum, t_map_info *map, t_square *sol)
{
	int i;
	int j;

	i = 1;
	while (i < map->lns)
	{
		j = 1;
		while (j < map->col)
		{
			if (tab[i][j] == 1)
			{
				sum[i][j] = give_value(i, j, sum, sol);
			}
			else
				sum[i][j] = 0;
			j++;
		}
		i++;
	}
	return (sum);
}

t_square	bsq(int **tab, t_map_info *code)
{
	t_square	sol;
	int			**sum;
	int			i;

	sum = ft_create_tab(code->lns, code->col);
	i = 0;
	while (i < code->col)
	{
		sum[0][i] = tab[0][i];
		i++;
	}
	i = 0;
	while (i < code->lns)
	{
		sum[i][0] = tab[i][0];
		i++;
	}
	sum = fill(tab, sum, code, &sol);
	ft_free_tab(sum, code->lns);
	return (sol);
}
