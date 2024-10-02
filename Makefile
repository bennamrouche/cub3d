# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:27:41 by mel-aini          #+#    #+#              #
#    Updated: 2023/07/18 13:36:28 by  ebennamr        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRC = mandatory/cub3d.c \
	mandatory/rendering/rendering.c mandatory/rendering/cast_rays.c mandatory/rendering/textures.c mandatory/rendering/shapes.c \
	mandatory/events/events.c mandatory/parsing/map_content.c mandatory/parsing/map_content_utils.c mandatory/parsing/map_content_ex_utils.c mandatory/parsing/map_infos.c mandatory/utils/error.c mandatory/utils/string.c mandatory/utils/utils.c \
	mandatory/get_next_line/get_next_line.c mandatory/get_next_line/get_next_line_utils.c \
	mandatory/lib/ft_bzero.c mandatory/lib/ft_isdigit.c mandatory/lib/ft_itoa.c mandatory/lib/ft_lstclear.c mandatory/lib/ft_lstnew.c mandatory/lib/ft_memset.c mandatory/lib/ft_strchr.c mandatory/lib/ft_strjoin.c mandatory/lib/ft_strlcpy.c mandatory/lib/ft_strncmp.c mandatory/lib/ft_substr.c \
	mandatory/lib/ft_calloc.c mandatory/lib/ft_lstadd_back.c mandatory/lib/ft_lstdelone.c mandatory/lib/ft_lstsize.c mandatory/lib/ft_split.c mandatory/lib/ft_strdup.c mandatory/lib/ft_strlen.c mandatory/lib/ft_strrchr.c mandatory/rendering/rendering_helper.c

SRC_BONUS = bonus/cub3d.c \
	bonus/rendering/rendering.c bonus/rendering/cast_rays.c bonus/rendering/cast_rays_utils.c bonus/rendering/textures.c bonus/rendering/minimap.c bonus/rendering/minimap_utils.c bonus/rendering/shapes.c bonus/rendering/sprites.c bonus/rendering/sprites_utils.c bonus/rendering/portal.c bonus/rendering/doors.c \
	bonus/events/events.c bonus/parsing/map_content.c bonus/parsing/map_content_utils.c bonus/parsing/map_content_ex_utils.c bonus/parsing/map_infos.c bonus/utils/init.c bonus/utils/init_utils.c bonus/utils/error.c bonus/utils/string.c bonus/utils/utils.c \
	bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c \
	bonus/lib/ft_bzero.c bonus/lib/ft_isdigit.c bonus/lib/ft_itoa.c bonus/lib/ft_lstclear.c bonus/lib/ft_lstnew.c bonus/lib/ft_memset.c bonus/lib/ft_strchr.c bonus/lib/ft_strjoin.c bonus/lib/ft_strlcpy.c bonus/lib/ft_strncmp.c bonus/lib/ft_substr.c \
	bonus/lib/ft_calloc.c bonus/lib/ft_lstadd_back.c bonus/lib/ft_lstdelone.c bonus/lib/ft_lstsize.c bonus/lib/ft_split.c bonus/lib/ft_strdup.c bonus/lib/ft_strlen.c bonus/lib/ft_strrchr.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADERS = mandatory/cub3d.h mandatory/events/events.h mandatory/parsing/parsing.h \
	mandatory/rendering/rendering.h mandatory/utils/utils.h mandatory/get_next_line/get_next_line.h mandatory/lib/libft.h

HEADERS_BONUS = bonus/cub3d.h bonus/events/events.h bonus/parsing/parsing.h bonus/rendering/rendering.h \
	bonus/utils/utils.h mandatory/get_next_line/get_next_line.h mandatory/lib/libft.h

FLAGS = -Wall -Wextra -Werror -g -Ofast

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	cc $(FLAGS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $@

mandatory/%.o : mandatory/%.c $(HEADERS)
	cc $(FLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(HEADERS_BONUS)
	cc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
