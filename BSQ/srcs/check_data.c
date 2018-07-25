/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:13:13 by nalonso           #+#    #+#             */
/*   Updated: 2018/07/25 23:31:51 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		nb_cols(char *str)
{
	int count;

	count = 0;
	while (*str != '\n')
		str++;
	str++;
	while (str[count] != '\n')
		count++;
	return (count++);
}

int		check_data(t_map_info *code, char *data)
{
	if (!(check_code(code, data)))
		return (0);
	code->lns = ft_atoi(data);
	code->col = nb_cols(data);
	if (!(check_y(data, code->lns)))
		return (0);
	if (!(check_x(data, code->col, code->lns)))
		return (0);
	return (1);
}

int		check_code(t_map_info *code, char *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data[i] != '\n')
		i++;
	if (i < 4 || i > 13)
		return (0);
	if (!((data[0] > 47) && (data[0] < 58)))
		return (0);
	if (data[i + 1] == '\0' || data[i + 1] == '\n')
		return (0);
	if (data[i - 1] == data[i - 2] || data[i - 2] == data[i - 3]
			|| data[i - 1] == data[i - 3])
		return (0);
	code->fch = data[i - 1];
	code->och = data[i - 2];
	code->ech = data[i - 3];
	return (1);
}

int		check_y(char *dest, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\n')
		i++;
	i++;
	while (dest[i + 1] != '\0')
	{
		if (dest[i + 1] == '\n')
			j++;
		i++;
	}
	return (y == j ? 1 : 0);
}

int		check_x(char *dest, int x, int y)
{
	int	i;
	int	j;
	int	k;
	int ok;

	i = 0;
	j = 0;
	k = 0;
	ok = 0;
	escape_code(&dest);
	while (dest[i] != '\0' && k < y)
	{
		while (dest[j + i] != '\n')
			j++;
		k++;
		if (x * k == j)
			ok = 1;
		else
			return (0);
		i++;
	}
	return (1);
}
