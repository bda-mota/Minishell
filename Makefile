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
CFILES		:=  main.c \
				token/token.c token/linked_list_token.c token/handle_word.c token/check_grammar.c token/handle_metha.c \
				token/check_inputs.c token/rearrange.c token/rearrange_utils.c token/variable_expansion.c token/variable_expansion2.c \
				utils/free_memory.c utils/init.c utils/get_set.c utils/is_redir.c utils/environ_copy.c utils/utils.c \
				heredoc/heredoc.c heredoc/heredoc_aux.c heredoc/heredoc_expansion.c \
				ast/build_tree.c ast/tree_utils.c ast/search_branch.c exec/command.c \
				exec/execution.c exec/path.c exec/pipe.c exec/redirects.c exec/execution_aux.c exec/treat_errors.c \
				builtins/execute_builtins.c builtins/ft_echo.c builtins/ft_export.c builtins/export_utils.c builtins/export_utils2.c \
				builtins/ft_pwd.c builtins/ft_unset.c builtins/ft_env.c builtins/ft_cd.c builtins/ft_exit.c \
				signals/initialize_signals.c signals/handler_signals.c

#PATH_FILES
SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

#HEADERS
HEADERS		:= -I ./includes
HEADER_FILE := includes/structs.h includes/minishell.h includes/token.h includes/ast.h includes/exec.h includes/builtins.h includes/heredoc.h

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

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -q --track-origins=yes --track-fds=yes --trace-children=yes --trace-children-skip='*/bin/*,*/sbin/*' --suppressions=.readline.supp ./$(NAME)

clear:
	clear
	$(MAKE) all

re: fclean all

.PHONY: all, clean, fclean, re
