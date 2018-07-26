/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:49:09 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/26 20:21:52 by martgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include “ft_stock_par.h”

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb < 10)
	{
		ft_putchar((char)(nb + '0'));
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((char)(nb % 10 + '0'));
	}
}

void	ft_print_words_tables(char **tab)
{
	char *pstr;

	while (*tab)
	{
		pstr = *tab;
		while (*pstr)
			ft_putchar(*pstr++);
		ft_putchar('\n');
		++tab;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	t_stock_par		*param;
	char			*pstr;

	param = par;
	while (param->str)
	{
		pstr = param->str;
		while (*pstr)
			ft_putchar(*pstr++);
		ft_putchar('\n');
		ft_putnbr(param->size_param);
		ft_putchar('\n');
		ft_print_words_tables(param->tab);
		++param;
	}
}
