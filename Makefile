NAME = fdf

HEADER = fdf_src/fdf.h 

LIST_C = fdf_src/main.c gnl/get_next_line.c gnl/get_next_line_utils.c \
libft/ft_atoi.c libft/ft_split_ex.c libft/ft_toupper.c \
fdf_src/color.c fdf_src/get_z.c fdf_src/get_xyz.c fdf_src/drawline.c fdf_src/drawmap.c \
fdf_src/display_settings.c fdf_src/set_disp_settings.c fdf_src/errmes.c

OBJ_C = ${patsubst %.c, %.o, ${LIST_C}}

FLAGS = -Wall -Wextra -Werror

FRAMEW = -lmlx -framework OpenGL -framework AppKit

all : ${NAME} 

${NAME} : ${OBJ_C}
	gcc -o ${NAME} ${FLAGS} ${FRAMEW} ${OBJ_C}

%.o : %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

clean :
	rm -f ${OBJ_C} 

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re 