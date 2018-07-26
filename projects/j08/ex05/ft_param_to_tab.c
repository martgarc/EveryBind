/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:17:37 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/26 20:19:00 by martgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int				i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char				*ft_strdup(char *src)
{
	char			*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*starr;
	int				i;

	starr = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		starr[i].size_param = strlen(av[i]);
		starr[i].str = av[i];
		starr[i].copy = ft_strdup(av[i]);
		starr[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	starr[i].str = 0;
	return (starr);
}
