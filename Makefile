# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 15:18:38 by abbahoua          #+#    #+#              #
#    Updated: 2022/06/13 13:46:36 by abbahoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	creating_philo.c\
	ft_atoi.c\
	philo_utils.c\
	check_args.c\
	mutex_init.c\

OBJS = $(SRC:.c=.o)

GCC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = philo

PTHREAD = -lpthread

all : $(NAME)

$(NAME) : $(OBJS)
		$(GCC) $(FLAGS) $(PTHREAD) $(SRC) -o $(NAME)

clean :
		$(RM) $(OBJS)
		
fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re