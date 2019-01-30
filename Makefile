NAME	=	fractol
OS		=	$(shell uname)

# directories
SRCDIR	= ./src
INCDIR	= ./include
OBJDIR	= ./obj

# sources
SRC		=	main.c \
			hooker.c \
			freer.c \
			supply.c \
			initer.c \
			bonus.c \
			fractals/mandelbrot.c

OBJ		=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra #-Werror

# ft lib
FT_LIB	=	$(addprefix $(FT),libft.a)
FT		=	./lib/libft/
FT_INC	=	-I ./lib/libft
FT_LNK	=	-L ./lib/libft -lft

# mlx lib
ifeq ($(OS), Linux)
MLX 	=	./lib/libmlx/
MLX_LNK	=	-L $(MLX) -lmlx -lXext -lX11
else
MLX		=	./lib/libmlx_macos/
MLX_LNK =	-L ./lib/libmlx_macos/ -lmlx -framework OpenGL -framework AppKit
endif
MLX_INC =	-I $(MLX)
MLX_LIB =	$(addprefix $(MLX),mlx.a)

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lpthread -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
