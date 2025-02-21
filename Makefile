NAME	= pipex

LIBFT	= ./libft/libft.a

LIBPATH	= ./libft

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g -I libft

SRCS	= pipex.c\
		utils.c\
		error.c

BSRCS	= bonus/pipex_bonus.c\
		bonus/utils_bonus.c\
		bonus/path_utils_bonus.c\
		bonus/heredoc_bonus.c\
		bonus/many_bonus.c\
		bonus/error_bonus.c

OBJS	= $(SRCS:.c=.o)

BOBJS	= $(BSRCS:.c=.o)

RM		= rm -rf

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
			@rm -f .bonus

bonus: .bonus

.bonus:		$(BOBJS) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(LIBFT)
			@touch .bonus

$(LIBFT): $(LIBPATH)
				$(MAKE) -C $^

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(BOBJS)
		$(MAKE) -C $(LIBPATH) clean
		rm -f .bonus

bonusclean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBPATH) fclean

re: fclean all
