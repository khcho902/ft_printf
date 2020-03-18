NAME = libft.a

SRCS = $(wildcard ft_[!l]*.c)
SRCS_B = $(wildcard ft_[l]*.c)

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

INCS = .

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar -rcs
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCS)

all: $(NAME)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus : $(NAME) $(OBJS_B)
	$(LIBC) $(NAME) $(OBJS_B)

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re .c.o
