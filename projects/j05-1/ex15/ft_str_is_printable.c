/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:10:47 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/11 21:25:38 by martgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_printable(char c)
{
	if ((c >= ' ' && c <= '~'))
		return (1);
	else
		return (0);
}

int		ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (check_printable(*str) == 1)
			str++;
		else
			return (0);
	}
	return (1);
}
