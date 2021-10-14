# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 19:56:08 by gcollet           #+#    #+#              #
#    Updated: 2021/10/14 10:30:53 by gcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_B	= philo_bonus

SRCS_B 	= srcs/main_bonus.c srcs/utils_bonus.c srcs/init_bonus.c srcs/routine_bonus.c

OBJS_B	= ${SRCS_B:.c=.o}

HEADER_B = -Iinclude

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		
					@$(CC) ${CFLAGS} ${HEADER_B} -c $< -o $(<:.c=.o)

all:	${PROG_B}

${PROG_B}:	${OBJS_B}
					@$(CC) ${HEADER_B} ${OBJS_B} -o ${PROG_B} -lpthread
					@echo "\n\033[32m\033[1m  BONUS Compiled\n\033[0m"
					
clean:
					@rm -f ${OBJS_B}

fclean: 	clean
					@rm -f ${PROG_B}

re:			fclean all

emote:	
					@echo "▒▒▒▒▒▒▒▒▄▄▄▄▄▄▄▄▄▄▒▒▒▒▒▒▒▒"
					@echo "▒▒▒▒▒▄█▀▀░░░░░░░░▀▀█▄▒▒▒▒▒"
					@echo "▒▒▒▄█▀▄██▄░░░░░░░░░░▀█▄▒▒▒"
					@echo "▒▒█▀░▀░░▄▀░░░░░░▄▀▀▀▀░▀█▒▒"
					@echo "▒█▀░░░░███░░░░░░▄█▄░░░░▀█▒"
					@echo "▒█░░░░░░▀░░░░░░░▀█▀░░░░░█▒"
					@echo "▒█░░░░░░░░░░░░░░░░░░░░░░█▒"
					@echo "▒█░░██▄░░▀▀▀▀▄▄░░░░░░░░░█▒"
					@echo "▒▀█░█░█░░░▄▄▄▄▄░░░░░░░░█▀▒"
					@echo "▒▒▀█▀░▀▀▀▀░▄▄▄▀░░░░░░▄█▀▒▒"
					@echo "▒▒▒█░░░░░░▀█░░░░░░░▄█▀▒▒▒▒"
					@echo "▒▒▒█▄░░░░░▀█▄▄▄▄▄█▀▀▒▒▒▒▒▒"
					@echo "▒▒▒▒▀▀▀▀▀▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"

.PHONY: all clean fclean re