# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hardella <hardella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 14:19:06 by hardella          #+#    #+#              #
#    Updated: 2022/08/06 14:19:12 by hardella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c




OBJS = $(SRCS:.c=.o)

NAME = miniRT

CFLAGS = -Wall -Wextra -Werror

.PHONY: 	clean fclean all re bonus

all:		$(NAME)

.c.o:
			gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./MinilibX
			gcc -o $(NAME) $(OBJS) $(CFLAGS) -lmlx -L./MinilibX -framework OpenGL -framework AppKit

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all
