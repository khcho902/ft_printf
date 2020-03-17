NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT_LIB = libft.a

SRCS = ./ft_printf.c \
       ./ft_conversion_handler.c \
       ./ft_printf_putchar.c \
       ./ft_isinset.c \
       ./ft_get_specifier.c \
       ./ft_set_flag.c \
       ./ft_printf_converter_char.c \
       ./ft_printf_converter_string.c \
       ./ft_printf_converter_pointer.c


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
	make all -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)
	####나중에 지울꺼####
	$(RM) a.out

re : fclean all


####나중에 지울꺼####
cleanprintf :
	$(RM) $(OBJS)

fcleanprintf : cleanprintf
	$(RM) $(NAME)
	$(RM) a.out

test : all
	$(CC) $(CFLAGS) main.c -I$(INCS) -L. -lftprintf



.PHONY : all clean fclean re .c.o
