/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:17:37 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/23 15:02:42 by martgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int		ft_wordlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int		ft_count_words(char *str)
{
	int i;
	int n;

	i = 1;
	n = 0;
	while (str[i - 1] != '\0')
	{
		if (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
			if (!(str[i - 1] == 32 || str[i - 1] == '\t'
						|| str[i - 1] == '\n'))
				n++;
		i++;
	}
	return (n);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while ((str[i] != '\0') && (str[i] != 32) && (str[i] != '\t')
			&& (str[i] != '\n'))
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*srcdup;
	int		i;

	i = 0;
	srcdup = (char*)malloc(sizeof(char) * (ft_wordlen(src) + 1));
	while ((src[i] != '\0') && (src[i] != 32) && (src[i] != '\t')
			&& (src[i] != '\n'))
	{
		srcdup[i] = src[i];
		i++;
	}
	srcdup[i] = '\0';
	return (srcdup);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		words;
	char	**tab;

	i = 0;
	words = ft_count_words(str);
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (*str == 32 || *str == '\t' || *str == '\n')
			str++;
		tab[i] = ft_strdup(str);
		while ((*str != 32) && (*str != '\t') && (*str != '\n' && *str != '\0'))
			str++;
		i++;
	}
	tab[words] = NULL;
	return (tab);
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*starr;
	int 			i;

	starr = (struct*)malloc(sizeof(s_stock_par) * (ac + 1));
	i = 0;
	while (av[i])
	{
		starr[i].size_param = strlen(av[i]);
		starr[i].str = &av[i];
		starr[i].copy = strcpy(av[i]);
		starr[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	starr[i].str = '0';
	return (starr);
}
