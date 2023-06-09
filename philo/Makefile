# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 17:09:26 by jvasseur          #+#    #+#              #
#    Updated: 2023/06/09 16:26:37 by jvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang -gdwarf-4 -g -pthread

CFLAGS = -Wall -Wextra -Werror 

NAME = philo

NAME_BONUS = philo

SRC = src/philo.c src/check_death.c src/fonction_utils.c src/parsing.c src/init.c src/program_philo.c src/time_utils.c

SRC_BONUS = 

MAKE = make -C

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

bonus : ${OBJ_BONUS}
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS)
	
all : $(NAME)

clean :
	rm -f $(OBJ) ${OBJ_BONUS}

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
