# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 14:19:06 by hardella          #+#    #+#              #
#    Updated: 2022/08/06 21:29:10 by yironmak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS_DIR	= ./src/includes/

SRCS_DIR	= ./src/

SRC 		= main.c figures/sphere.c geometry/vector.c scene/camera.c utils/errors.c \
			scene/scene.c ray_tracing/trace_ray.c intersections/sphere_intersect.c

SRCS 		= $(addprefix $(SRCS_DIR), $(SRC))

OBJS 		= $(SRCS:.c=.o)

NAME 		= miniRT

CFLAGS 		= -Wall -Wextra -Werror

.PHONY: 	clean fclean all re bonus

.c.o:
			gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./MinilibX
			gcc -o $(NAME) $(OBJS) $(CFLAGS) -lmlx -L./MinilibX -framework OpenGL -framework AppKit

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all
