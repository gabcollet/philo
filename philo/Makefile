# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 19:56:08 by gcollet           #+#    #+#              #
#    Updated: 2021/10/05 15:13:20 by gcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= philo
PROG_B	= philo_bonus

SRCS 	= srcs/main.c srcs/utils.c srcs/init.c srcs/routine.c
SRCS_B 	= bonus/philo_bonus/main_bonus.c bonus/philo_bonus/utils_bonus.c \
			bonus/philo_bonus/init_bonus.c bonus/philo_bonus/routine_bonus.c
OBJS 	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

HEADER	= -Iinclude
HEADER_B = -Ibonus

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		
					@$(CC) ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all:	${PROG}

${PROG}:	${OBJS}
					@$(CC) ${OBJS} -o ${PROG} -lpthread
					@echo "\n\033[32m\033[1m  Philosophers Compiled\n\033[0m"

bonus:	${PROG_B}

${PROG_B}:	${OBJS_B}
					@$(CC) ${HEADER_B} ${OBJS_B} -o ${PROG_B} -lpthread
					@echo "\n\033[32m\033[1m  BONUS Compiled\n\033[0m"
					
clean:
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@rm -f ${PROG} ${PROG_B}

re:			fclean all

re_bonus:	fclean bonus

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