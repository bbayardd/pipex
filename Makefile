
NAME = pipex

SRCS = 	ft_putstr_fd.c pipex.c ft_strdup.c ft_strlcpy.c utils.c\
		ft_strjoin.c  ft_split.c ft_putchar_fd.c ft_strlen.c\
		ft_putnbr_fd.c find_path.c  clean.c\

INCLUDE	=	pipex.h

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE)

all		:	$(NAME)

 %.o : %.c	$(INCLUDE)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
			
$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(SRCS) -I./include -o $(NAME)

clean	:
		@rm -rf $(OBJS)

fclean	:	clean
		@rm -rf $(NAME)

re		:	fclean all

.PHONY: clean fclean re all
