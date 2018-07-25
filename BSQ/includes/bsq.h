/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 02:10:58 by nalonso           #+#    #+#             */
/*   Updated: 2018/07/25 23:34:39 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct	s_list
{
	char			data;
	struct s_list	*next;
}				t_list;

typedef struct	s_square
{
	int				x;
	int				y;
	int				size;
}				t_square;

typedef struct	s_map_info
{
	int				lns;
	int				col;
	char			fch;
	char			ech;
	char			och;
}				t_map_info;

/*
** help.c - Ft Functions
*/
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_malloc_error(void);
void			ft_free_tab(int **tab, int rows);
void			ft_free_list(t_list *list);
int				ft_atoi(char *str);
int				**ft_create_tab(int rows, int cols);
/*
** process_data.c - create tab
*/
int				**map_creator(char *str, t_map_info *code);
void			escape_code(char **str);
void			aument(int *a, int *b);
/*
** check_data.c - check if map is valid
*/
int				check_data(t_map_info *code, char *data);
int				check_code(t_map_info *code, char *data);
int				check_y(char *dest, int y);
int				check_x(char *dest, int x, int y);
/*
** read_data.c - read stdin and files
*/
t_list			*create_elem(char ch);
void			push_list(t_list **begin_list, char ch);
char			*concat_list(t_list *list, int len);
char			*read_stdin(void);
char			*read_data(char *arg);
/*
** bsq.c - main algorithm
*/
t_square		bsq(int **tab, t_map_info *code);
void			print_data(t_map_info *code, t_square *sol, int **tab);
int				give_value(int i, int j, int **sum, t_square *sol);
int				**fill(int **tab, int **sum, t_map_info *map, t_square *sol);
int				**create_sum(int rows, int cols);
#endif
