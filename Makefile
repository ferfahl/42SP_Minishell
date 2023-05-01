NAME			= minishell

CFLAGS			= -g3 -g -Wall -Werror -Wextra
LFLAGS			= -lft -lreadline
INCLUDES		= -I./includes -I$(LIBFT_INC)
LIBS			= -L./libs/libft

#libft
LIBFT_PATH		= ./libs/libft
LIBFT_INC		= $(LIBFT_PATH)/includes
LIBFT			= $(LIBFT_PATH)/libft.a

#list path
BUILTINS_PATH	= builtins/
SIGNALS_PATH	= signals/
COMMANDS_PATH	= commands/
INPUT_PATH		= input/
REDIRECT_PATH	= redirects/
ENVP_PATH		= environment/
MINISHELL_PATH	= mini_hell/
QUOTES_PATH		= quotes/

#source codes
SRC_DIR			=	./srcs/
SRC_LIST		=	minishell.c							\
					$(MINISHELL_PATH)terminal_line.c	\
					$(MINISHELL_PATH)init_minishell.c	\
					$(MINISHELL_PATH)free_minishell.c	\
					$(MINISHELL_PATH)ft_utils.c	\
					$(MINISHELL_PATH)exit.c				\
					$(ENVP_PATH)environment.c			\
					$(SIGNALS_PATH)signals.c			\
					$(COMMANDS_PATH)commands.c			\
					$(COMMANDS_PATH)commands_list.c		\
					$(COMMANDS_PATH)commands_utils.c	\
					$(INPUT_PATH)input_checkers.c		\
					$(INPUT_PATH)validate_input.c		\
					$(QUOTES_PATH)compress_quotes.c		\
					$(QUOTES_PATH)decompress_quotes.c	\
					$(INPUT_PATH)check_symbols.c		\
					$(BUILTINS_PATH)ft_pwd.c			\
					# $(BUILTINS_PATH)ft_cd.c				\
					# $(BUILTINS_PATH)ft_echo.c			\
					# $(BUILTINS_PATH)ft_env.c			\
					# $(BUILTINS_PATH)ft_exit.c			\
					# $(BUILTINS_PATH)ft_export_check.c		\
					# $(BUILTINS_PATH)ft_export.c			\
					# $(BUILTINS_PATH)ft_unset.c			\

SRCS			= $(addprefix $(SRC_DIR), $(SRC_LIST))

#objects
OBJS_DIR		= ./objects/
OBJS			= $(addprefix $(OBJS_DIR),$(SRC_LIST:%.c=%.o))

#colors
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET			= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	@printf "\n"
	@gcc $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) -o $(NAME)
	@echo " $(CYAN)$(NAME): $(GREEN)Done!"
	@echo -n "$(RESET)"

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(ENVP_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(MINISHELL_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(SIGNALS_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(COMMANDS_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(INPUT_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(QUOTES_PATH))
	@mkdir -p $(addprefix $(OBJS_DIR)/,$(BUILTINS_PATH))
#	@mkdir -p $(addprefix $(OBJS_DIR)/,$(REDIRECT_PATH))

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(YELLOW)Generating $(CYAN)$(NAME) $(YELLOW)objects... %-33.33s\r" $@

clean:
	@make -sC $(LIBFT_PATH) clean
	@rm -rf $(OBJS_DIR)	

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@rm -f $(NAME)

run: all
	./$(NAME)

val:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=./readline.supp -q ./$(NAME)

re: fclean all

coffee:
	@make -sC $(LIBFT_PATH) coffee

#make git m="message" -> commit to git
git:
		git add .
		git commit -m "$(m)"
		git push

norm:
		clear
		@norminette ${addprefix ${SRC_DIR}/, ${SRC_LIST}} | grep -v "OK!" || echo "All files ok!"

.PHONY: all clean fclean re coffee run val