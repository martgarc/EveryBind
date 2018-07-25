/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 02:25:12 by nalonso           #+#    #+#             */
/*   Updated: 2018/07/25 21:42:01 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_list	*create_elem(char ch)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		ft_malloc_error();
	list->next = NULL;
	list->data = ch;
	return (list);
}

void	push_list(t_list **begin_list, char ch)
{
	t_list	*list;

	list = *begin_list;
	if (!list)
	{
		*begin_list = create_elem(ch);
		return ;
	}
	while (list->next != NULL)
		list = list->next;
	list->next = create_elem(ch);
}

char	*concat_list(t_list *list, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = "\0";
	if (list)
	{
		if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
			ft_malloc_error();
		while (i < len)
		{
			str[i] = list->data;
			list = list->next;
			i += 1;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*read_stdin(void)
{
	t_list	*list;
	char	buf;
	char	*str;
	int		len;

	list = NULL;
	len = 0;
	while (read(0, &buf, sizeof(buf)) > 0)
	{
		push_list(&list, buf);
		len += 1;
	}
	str = concat_list(list, len);
	ft_free_list(list);
	return (str);
}

char	*read_data(char *arg)
{
	int		fd;
	int		len;
	char	*str;
	char	buf;
	t_list	*list;

	list = NULL;
	len = 0;
	fd = open(arg, O_RDONLY);
	while (read(fd, &buf, sizeof(buf)) > 0)
	{
		push_list(&list, buf);
		len += 1;
	}
	close(fd);
	str = concat_list(list, len);
	ft_free_list(list);
	return (str);
}
