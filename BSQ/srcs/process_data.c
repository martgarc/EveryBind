/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 01:48:39 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/25 22:19:16 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	escape_code(char **str)
{
	while (**str != '\n')
		*str = *str + 1;
	*str = *str + 1;
}

void	aument(int *a, int *b)
{
	*a = *a + 1;
	*b = *b + 1;
}

int		**map_creator(char *str, t_map_info *code)
{
	int		i;
	int		j;
	int		n;
	int		**tab;

	i = 0;
	n = 0;
	tab = ft_create_tab(code->lns, code->col);
	escape_code(&str);
	while (i < code->lns)
	{
		j = 0;
		while (str[n] != '\n')
		{
			if (str[n] == code->ech)
				tab[i][j] = 1;
			else
				tab[i][j] = 0;
			aument(&j, &n);
		}
		tab[i][j] = '\0';
		aument(&i, &n);
	}
	tab[i] = NULL;
	return (tab);
}
