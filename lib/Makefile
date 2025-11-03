#Variables
NAME = libft.a
SRC = ft_*.c
OBJ = $(SRC:*.c=*.o)
N = norminette
CFLAG = -Werror -Wall -Wextra 

#regles
all : $(OBJ)
	gcc $(CFLAG) $< -o $(NAME)

*.o : *.c libft.h
	gcc $(CFLAG) $< -o $@

clear :
	rm -f $(OBJ)

fclear : clear
	rm -f $(NAME)

re : fclear all

n :
	$(N)