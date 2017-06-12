##
## Makefile for scroller in /home/ibanez_j/parallax
## 
## Made by Jean-Alexandre IBANEZ
## Login   <ibanez_j@epitech.net>
## 
## Started on  Mon Jun 12 10:46:14 2017 Jean-Alexandre IBANEZ
## Last update Mon Jun 12 10:51:24 2017 Jean-Alexandre IBANEZ
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -I./include

NAME	= scroller

SRCS	= ./srcs/destroy_graph.c	\
	  ./srcs/init_functions.c	\
	  ./srcs/keyboard_actions.c	\
	  ./srcs/loop.c			\
	  ./srcs/main.c			\
	  ./srcs/menu.c			\
	  ./srcs/mouse_actions.c	\
	  ./srcs/music.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lc_graph_prog_full -lm

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY:	all re clean fclean
