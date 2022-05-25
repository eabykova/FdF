# FOR MAC_OS
NAME	=	fdf
NAME_B	=	fdf_bonus

HEAD	=	fdf.h
HEAD_B	=	fdf_bonus.h

SRC		=	fdf.c \
				src/key_discover.c \
				src/key_discover1.c \
				src/map_utils.c \
				src/map_utils1.c \
				src/put_map.c \
				src/read_map.c \
				src/rotations.c \
				src/start_window.c

SRC_B		=	fdf_bonus.c \
				src/key_discover_bonus.c \
				src/key_discover1_bonus.c \
				src/map_utils_bonus.c \
				src/map_utils1_bonus.c \
				src/put_map_bonus.c \
				src/read_map_bonus.c \
				src/rotations_bonus.c \
				src/start_window_bonus.c

LIB_DIR	=	./lib/
LIB		=	libft.a
MLX_DIR	=	./mlx/
MLX		=	$(MLX_DIR)libmlx.a

OBJ		=	$(SRC:%.c=%.o)
OBJ_B	=	$(SRC_B:%.c=%.o)

D_FIL	=	$(SRC:%.c=%.d)
D_FIL_B	=	$(SRC_B:%.c=%.d)

FLAG	=	-Imlx -g -Wall -Werror -Wextra
#-fsanitize=address -g

CC		=	gcc -O2 -MD
RM		=	rm -f

.PHONY		:	all clean fclean re bonus

all			:	libmake $(NAME) Makefile

$(NAME)		:	$(OBJ) $(LIB_DIR)$(LIB)
	$(CC) $(FLAG) $(OBJ) $(LIB_DIR)$(LIB) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "✅	Ready. Enjoy     ✅ "

bonus		:	 all $(NAME_B) Makefile

$(NAME_B)	:	$(OBJ_B) $(LIB_DIR)$(LIB)
	$(CC) $(FLAG) $(OBJ_B) $(LIB_DIR)$(LIB) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
	@echo "✅	Bonus is ready. Enjoy     ✅ "

libmake	:
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)

%.o		:	%.c $(HEAD) $(HEAD_B)
	$(CC) $(FLAG) -c $< -o $@

include $(wildcard $(D_FIL) $(D_FIL_B))

clean		:
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)

	$(RM) $(OBJ) $(D_FIL) $(OBJ_B) $(D_FIL_B)
fclean		:	clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME) $(NAME_B)

re		:	fclean all
