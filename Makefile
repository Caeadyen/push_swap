# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrings <hrings@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 19:49:19 by hrings            #+#    #+#              #
#    Updated: 2022/04/23 11:40:37 by hrings           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CHECK = checker
CC = gcc

CFLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = $(FT_LNK) 
INCLUDES = $(FT_INC)
HEADER = ./header
SRCDIR = src/

LIBFT = $(LIBFT_DIRECTORY)/libft.a
LIBFT_DIRECTORY = ./libft
FT_INC	= -I ./libft/
FT_LNK	= ./libft/libft.a


OBJDIR = build/
OBJDIRBONUS = bonusbuild/

SRCS := main.c utilities.c pb.c pa.c ra.c rb.c rr.c \
		rra.c rrb.c rrr.c preparation.c sortbig.c \
		find_moves.c commands.c find_min.c stack.c \
		error.c list.c sa.c sb.c ss.c sorting.c \
		sortfive.c ssa.c ssb.c

OBJECTS := $(SRCS:.c=.o)
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJECTS))

SRCSB := error.c main.c pa.c pb.c ra.c rb.c rra.c \
		rrb.c rr.c rrr.c sa.c sb.c ssa.c ssb.c ss.c \
		utilities.c stack.c read_input.c

OBJECTSB := $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED := $(addprefix $(OBJDIRBONUS), $(OBJECTSB))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_PREFIXED) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJECTS_PREFIXED) $(LIBRARIES) -I$(HEADER) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"


$(OBJECTS_PREFIXED): build/%.o : src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c  $< -o $@ -I$(HEADER) $(INCLUDES)
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) all -sC $(LIBFT_DIRECTORY)

bonus: $(CHECK)

$(CHECK): $(LIBFT) $(OBJECTS_BONUS_PREFIXED) $(OBJDIRBONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS_PREFIXED) $(LIBRARIES) -I$(HEADER) -o $(CHECK)
	@echo "$(NAME): $(GREEN)$(CHECK) was created$(RESET)"

$(OBJECTS_BONUS_PREFIXED): bonusbuild/%.o : bonus/%.c
	@mkdir -p $(OBJDIRBONUS)
	$(CC) $(CFLAGS) -c  $< -o $@ -I$(HEADER) $(INCLUDES)
	@echo "$(GREEN).$(RESET)\c"

clean:
	@cd ./$(LIBFT_DIRECTORY) && make clean
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJDIRBONUS)
	@echo "$(NAME): $(RED)object files and directory were deleted$(RESET)"

fclean: clean
	@cd ./$(LIBFT_DIRECTORY) && make fclean
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJDIRBONUS)
	@rm -f $(NAME)
	@rm -f $(CHECK)
	@echo "$(NAME): $(RED)Libaries were deleted$(RESET)"

re: fclean all
