NAME		:= minishell
CFLAGS		:= -Wextra -Wall -Werror -g3
LFLAGS		:= -lreadline
MAKEFLAGS += --silent

# LIBRARIES_PATH
LIBFT_PATH = ./libft
LIBFT = $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH	:= objects

# SOURCES
CFILES		:= trash.c main.c \
				token/token.c token/linked_list_token.c token/1_separators.c token/2_separators.c token/3_separators_aux.c token/4_separators_aux.c \
				utils/error.c utils/get_last_node.c utils/get_list_size.c \
				ast/build_tree.c ast/down_tree.c

#PATH_FILES
SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

#HEADERS
HEADERS		:= -I ./includes
HEADER_FILE := includes/structs.h includes/minishell.h includes/token.h includes/ast.h

# COLORS
GREEN	:=	\033[1;32m
PURPLE	:=	\033[1;35m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

#LOADING BAR
TOTAL_FILES := $(words $(CFILES))
COMPILED_CFILES := 0

define progress_bar
	@tput cuu1
	@tput el
	@echo "$(GREEN)[========================================>] $(WHITE)($1/$(TOTAL_FILES))"
endef

all: $(OBJ_PATH) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "                                     "
	$(eval COMPILED_CFILES := $(shell echo $$(($(COMPILED_CFILES) + 1))))
	$(call progress_bar,$(COMPILED_CFILES),$(words $(CFILES)))

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(LFLAGS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)  ✅ The [$(GREEN)MINISHELL$(WHITE)] has been compiled! ✅ "
	@echo "$(GREEN)-------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@echo "                                     "
	@echo "$(WHITE)     Objects - $(RED)MINISHELL$(WHITE) - were cleaned!"
	@echo "                                     "

fclean: clean
	@echo "$(WHITE)              Cleaning all... 🧹"
	@echo "                                     "
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(WHITE)    ✨ Cleaning - MINISHELL - complete! ✨"
	@echo "                                     "

re: fclean all

.PHONY: all, clean, fclean, re
