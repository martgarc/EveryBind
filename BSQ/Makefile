#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalonso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 01:57:54 by nalonso           #+#    #+#              #
#    Updated: 2018/07/25 23:32:23 by nalonso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME := bsq

# Directories and files containing source files

SRCDIR = srcs/
SRCS := main.c bsq.c print_data.c process_data.c \
	read_data.c help.c help_2.c check_data.c
CFILES = $(addprefix $(SRCDIR), $(SRCS))

# Object files
OFILES = $(CFILES:.c=.o) 

HFILES = includes/bsq.h

FLAGS = -Wall -Werror -Wextra

CC := gcc

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OFILES)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


