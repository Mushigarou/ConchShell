FLAG = -Wall -Wextra -Werror 

INC = main/inc/mini_shell.h

RM = rm -rf

NAME = minishell

S_F = mini_shell.c

O_D = obj

S_D = main/src

OBJ = $(addprefix $(O_D)/,$(S_F:.c=.o))

SRC = $(addprefix $(S_D)/,$(S_F))

PRS = parsing/parsing.a

LIBTOOL = libtool/libft.a

all: $(O_D) $(NAME)

$(O_D):
	mkdir $@

$(NAME): $(OBJ) $(PRS) $(LIBTOOL)
	cc $(FLAG) -lreadline $^ -o $@

$(PRS):
	make -C parsing

$(LIBTOOL):
	make -C libtool

$(O_D)/%.o: $(S_D)/%.c $(INC)
	@cc $(FLAG) -c $< -o $@

clean:
	make -C libtool clean
	make -C parsing clean
	$(RM) $(O_D)

fclean: clean
	make -C libtool fclean
	make -C parsing fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re

.SILENT: all clean fclean re $(NAME) $(O_D) $(PRS) $(LIBTOOL)

