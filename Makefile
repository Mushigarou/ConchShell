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

all: start $(O_D) $(NAME)

start:
	clear
	printf "\r\n"
	echo "       	   :~-._                                                 _.-~:       "
	echo "       	   : :.~^o._        ________---------________        _.o^~.:.:       "
	echo "       	   : ::.'?88booo~~~.::::::::...::::::::::::..~~oood88P'.::.:         "
	echo "       	   :  ::: '?88P .:::....         ........:::::. ?88P' :::. :         "
	echo "       	    :  :::. '? .::.            . ...........:::. P' .:::. :          "
	echo "       	     :  :::   ... ..  ...       .. .::::......::.   :::. :           "
	echo "       	     '  :' .... ..  .:::::.     . ..:::::::....:::.  ': .'           "
	echo "       	       :..    ____:::::::::.  . . ....:::::::::____  ... :           "
	echo "       	      :... ':~    ^~-:::::..  .........:::::-~^    ~::.::::          "
	echo "       	      '.::. '\   \033[0;31m(8)\033[0m  \b:::..::.:.:::::::d/  \033[0;31m(8)\033[0m     /'.::::'          "
	echo "       	       ::::.  ~-._v  |b.::::::::::::::d|      v_.-~..:::::             "
	echo "       	       '.:::::... ~~^?888b..:::::::::::d888P^~...::::::::'           "
	echo "       	        '.::::::::::....~~~ .:::::::::~~~:::::::::::::::'            "
	echo "       	         '..:::::::::::   .   ....::::    ::::::::::::,'             "
	echo "       	           '. .:::::::    .     .::::.    ::::::::::'.                "
	echo "       	             '._ .:::    .  |     :::::.    :::::_.'                 "
	echo "       	                '-. :    .        :::::      :,-'                    "
	echo "       	                   :.   :___\    .:::___   .::                       "
	echo "       	         \033[0;33m..--~~~~--:\033[0m+::. ~~^?b..:::dP^~~.::++\033[0;33m:--~~~~--..\033[0m             "
	echo "       	           \033[0;33m___....--'\033[0m+:::.   \'~8~'/   .:::+\033[0;33m'--....___\033[0m               "
	echo "       	         \033[0;33m~~   __..---'\033[0m_=:: ___gd8bg___ :==_\033[0;33m'---..__   ~~\033[0m             "
	echo "       	          \033[0;33m-~~~  _.--~~'\033[0m-.~~~~~~~~~~~~~~~,-\033[0;33m' ~~--._ ~~~-\033[0m              "
	echo "       	              \033[0;33m-~~\033[0m        \ |~~~~~~~~~~~| /           \033[0;33m~~-\033[0m                "
	echo "       	                          \|  ~~~~~~~  |/                              \n"
	echo "\033[0;31m               ▄▄▄██▀▀▀▄▄▄        ▄████  █    ██  ▄▄▄       ██▀███     \033[0m" 
	echo "\033[0;31m                ▒██  ▒████▄     ██▒ ▀█▒ ██  ▓██▒▒████▄    ▓██ ▒ ██▒    \033[0m"
	echo "\033[0;31m                ░██  ▒██  ▀█▄  ▒██░▄▄▄░▓██  ▒██░▒██  ▀█▄  ▓██ ░▄█ ▒    \033[0m"
	echo "\033[0;31m             ▓██▄██▓ ░██▄▄▄▄██ ░▓█  ██▓▓▓█  ░██░░██▄▄▄▄██ ▒██▀▀█▄      \033[0m"
	echo "\033[0;31m              ▓███▒   ▓█   ▓██▒░▒▓███▀▒▒▒█████▓  ▓█   ▓██▒░██▓ ▒██▒    \033[0m"
	echo "\033[0;31m              ▒▓▒▒░   ▒▒   ▓▒█░ ░▒   ▒ ░▒▓▒ ▒ ▒  ▒▒   ▓▒█░░ ▒▓ ░▒▓░    \033[0m"
	echo "\033[0;31m              ▒ ░▒░    ▒   ▒▒ ░  ░   ░ ░░▒░ ░ ░   ▒   ▒▒ ░  ░▒ ░ ▒░    \033[0m"
	echo "\033[0;31m              ░ ░ ░    ░   ▒   ░ ░   ░  ░░░ ░ ░   ░   ▒     ░░   ░     \033[0m"
	echo "\033[0;31m              ░   ░        ░  ░      ░    ░           ░  ░   ░         \033[0m\n"                                             

$(O_D):
	mkdir $@

$(NAME): $(OBJ) $(PRS) $(LIBTOOL)
	cc $(FLAG) -lreadline $^ -o $@
	printf "\r\033[0;33mMINISHELL is ready to lunch enjoy 😉\033[0m\n"

$(PRS): 
	printf "\r\033[0;33m⏳ parsing is compiling ...\033[0m"
	make -C parsing

$(LIBTOOL):
	printf "\r\033[0;33m⏳ libtool is compiling ...\033[0m"
	make -C libtool

$(O_D)/%.o: $(S_D)/%.c $(INC)
	@cc $(FLAG) -c $< -o $@

clean: start 
	printf "\r\033[0;33mclearing object files 🚮🗑️ ...\033[0m"
	make -C libtool clean
	make -C parsing clean
	$(RM) $(O_D)

fclean: clean
	printf "\r\033[0;33mYOU DELETED MY MINISHELL 😱 YOU !*#^&# 😡🤬\033[0m\n"
	make -C libtool fclean
	make -C parsing fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re

.SILENT: all clean fclean re $(NAME) $(O_D) $(PRS) $(LIBTOOL) start

