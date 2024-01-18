# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                   		:+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 13:39:39 by mgeiger-          #+#    #+#              #
#    Updated: 2023/11/18 13:39:40 by mgeiger-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f

RED		=	\e[0;91m
BLUE	=	\e[0;94m
GREEN	=	\e[0;92m
YELLOW	=	\e[0;33m
WHITE	=	\e[0;97m
BOLD	=	\e[1m
U_LINE	=	\e[4m
RESET	=	\e[0m

FILES 		=	error_handling \
				extra \
				free \
				ft_itoa \
				ft_split \
				main \
				ps_init \
				push_swap \
				push \
				rev_rotate \
				rotate \
				sort \
				stack_init \
				swap \
				utils \

SRCS_DIR	=	./
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR	=	./
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	$(OBJS)
	@echo "$(YELLOW)Compliling ./push_swap$(RESET)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) built$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Removed .o files$(RESET)"

fclean: 	clean
	@$(RM) $(NAME)
	@echo "$(RED)All files cleaned$(RESET)"

re: 		clean all
	@echo "$(GREEN)Successfully cleaned and rebuilt library$(RESET)"

.PHONY: all clean fclean re	push_swap
