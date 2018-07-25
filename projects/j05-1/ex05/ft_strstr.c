/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:33:14 by martgarc          #+#    #+#             */
/*   Updated: 2018/07/12 21:47:38 by martgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char		*ft_strstr(char *str, char *to_find)
{
	int		n;
	char	*ptr;

	while (*str != '\0')
	{
		n = 0;
		while (*str != to_find[n])
		{
			str++;
		}
		ptr = str;
		while (*str == to_find[n])
		{
			if (to_find[n + 1] != '\0')
			{
				str++;
				n++;
			}
			else
				return (ptr);
		}
	}
	return (0);
}

int main(void) 
{
	char str[] = "qwertwertyuiy12321up";
	char str2[] = "12321";
	char *s1;
	char *s2;

	s1 = str;
	s2 = str2;
	printf("%s", ft_strstr(str, str2));
	return 0;
}
