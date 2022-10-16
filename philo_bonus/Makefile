NAME				= philo_bonus

LIB_DIR				= ./lib
LIBFT_DIR			= $(LIB_DIR)/libft
LIBFT_A				= $(LIBFT_DIR)/libft.a

HEAD_DIR			= ./include

FILES				= \
						main_bonus.c\
						parsing_init_bonus.c\
						parsing_list_bonus.c\
						philo_bonus.c\
						philo_bonus_2.c\
						utils_philo_bonus.c\
						error_bonus.c\
						exit_bonus.c\



SRCS_DIR			=	./srcs
SRCS				= \
						$(addprefix $(SRCS_DIR)/,$(FILES))\

OBJS_DIR			=	./objs
OBJS				= $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))

INCLUDES			= -I $(LIBFT_DIR) -I $(HEAD_DIR)
CFLAGS 				= -Wall -Wextra -Werror $(INCLUDES) -g -pthread #-fsanitize=address

GREEN 				= \033[01;32m
RESET 				= \033[00m

all:				$(NAME)

$(NAME):			libraries $(OBJS)
					@gcc -g $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
					@echo "$(GREEN)$(NAME) successfully compiled $(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@mkdir -p $(@D)
					@gcc -c -g $(CFLAGS) $< -o $@

$(OBJS): 			| $(OBJS_DIR)

$(OBJS_DIR):
					@mkdir $(OBJS_DIR)

libraries:			
					@printf "Making libft..." && make -C $(LIBFT_DIR)

clean:				
					@make clean -C $(LIBFT_DIR)
					@rm -f $(OBJS)
					@echo "$(GREEN)Successfully cleaned objects - $(NAME)$(RESET)"

fclean: 			clean
					@make fclean -C $(LIBFT_DIR)
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -rf $(OBJS_DIR)
					@echo "$(GREEN)Successfully forced cleaned - $(NAME)$(RESET)"

bis:				
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -rf $(OBJS_DIR)
					@echo "$(GREEN)Successfully cleaned binary and objects  - $(NAME)$(RESET)"
					@make

run:				bis
					@./philo
					@echo "$(GREEN)Successfully executed $(NAME)$(RESET)"


re: 				fclean all
.PHONY: 			all clean fclean re libraries bis run
