NAME = libft.a

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

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

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re .c.o
