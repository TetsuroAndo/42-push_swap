# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:37:09 by teando            #+#    #+#              #
#    Updated: 2024/12/09 10:27:26 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
ROOT_DIR	:= .
OUT_DIR		:= $(ROOT_DIR)/obj
INCS_DIR	:= $(ROOT_DIR)/inc
LIBFT_DIR	:= $(ROOT_DIR)/libft
LIBFT		:= $(LIBFT_DIR)/libft.a

IDFLAGS		:= -I$(INCS_DIR) -I$(LIBFT_DIR)

SRCS 		:= \
	$(addprefix src/, \
		$(addprefix ops/, \
			operations.c \
			push.c \
			rotate.c \
			rrotate.c \
			swap.c \
		)\
		$(addprefix sort/, \
			small_sort.c \
			sort.c \
			utils.c \
		)\
		error.c \
		main.c \
		parse.c \
		push_swap.c \
	)

OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(OBJS:.o=.d)

ifeq ($(DEBUG), 1)
	CFLAGS	+= -g -fsanitize=address
else
	CFLAGS	+= -O2
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OUT_DIR)/%.o: $(ROOT_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP $(IDFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OUT_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
	
lib:
	git clone https://github.com/TetsuroAndo/42-libft libft

norm:
	@norminette $(SRCS) $(INCS_DIR)

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re sub sub-update norm debug

-include $(DEPS)