CC		=	gcc

CFLAGS	=	-g -Wall -Wextra -Werror -I

# -fsanitize=address

HEADERS	=	./includes/

NAME	=	rt

LIBMLX	=	./minilibx-linux/libmlx.a

SRC		=	./base/main.c ./base/check_file.c ./base/render_utils.c \
			./base/render.c ./base/vec_dir.c ./base/window.c \
			./base/color.c ./base/vector1.c ./base/vector2.c \
			./base/free_data.c ./base/init_struct.c ./base/screenshot.c \
			./parser/atoi.c ./parser/calloc.c ./parser/gnl.c \
			./base/error.c \
			./parser/parser.c ./parser/parser_r_a.c \
			./parser/parser_l.c ./parser/parser_c.c \
			./parser/parser_sp.c ./parser/parser_pl.c \
			./parser/parser_tr.c ./parser/parser_sq.c \
			./parser/parser_cy.c ./parser/split.c \
			./parser/check_data.c ./parser/create_utils.c \
			./parser/free_parser.c \
			./obj/sphere.c ./obj/plane.c ./obj/obj_utils.c \
			./obj/triangle.c ./obj/square.c \
			./obj/cylinder.c 

OBJECTS	=	$(SRC:.c=.o)

# deps:=		$(SRC:.c=.d)

# -include $(deps)

# DEPFLAGS =	-MMD -MF $(@:.o=.d)

all:		$(LIBMLX) $(NAME)
	
%.o : %.c
			$(CC) -c $(CFLAGS) $(HEADERS) $< -o $@

$(NAME): 	$(OBJECTS) $(HEADERS)
			$(CC) $(CFLAGS) $(HEADERS) $(OBJECTS) -L ./minilibx-linux/ -lmlx_Linux -lXext -lX11 -lm -o $(NAME)
			@echo ""
			@echo "\033[1;33m▂▃▅▇█▓▒░ DONE ░▒▓█▇▅▃▂\033[0;39m"
			@echo ""

$(LIBMLX):	lib

lib:
			@$(MAKE) -C minilibx-linux --no-print-directory

clean:			
			@$(MAKE) clean -C minilibx-linux --no-print-directory
			rm -f $(OBJECTS)
			rm -f $(NAME)
			@echo ""
			@echo "\033[1;39mRemove \033[1;31m████████████]\033[39m 100%\033[0;39m"
			@echo ""

re:			clean all
			@echo "\033[1;32m┴┬┴┬┴┬┤ REMAKE ├┬┴┬┴┬┴\033[0;39m"
			@echo ""
