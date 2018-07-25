/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:02:48 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/19 21:30:42 by martgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	srcdup = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
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
