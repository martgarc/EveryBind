/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:26:09 by nalonso           #+#    #+#             */
/*   Updated: 2018/07/25 22:45:38 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_free_list(t_list *list)
{
	t_list *next;

	if (list == NULL)
		return ;
	while (list != NULL && list->next != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
	free(list);
}

int		**ft_create_tab(int rows, int cols)
{
	int **sum;
	int i;

	if (!(sum = (int**)malloc(sizeof(int *) * (rows + 1))))
		ft_malloc_error();
	i = 0;
	while (i < rows)
	{
		if (!(sum[i] = (int*)malloc(sizeof(int) * (cols + 1))))
			ft_malloc_error();
		i++;
	}
	return (sum);
}
